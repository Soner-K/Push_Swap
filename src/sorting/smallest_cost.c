/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:58:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/26 19:45:10 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Finds the maximum value's position in a stack.
 * @param stack Pointer to the first node of a stack.
 * @returns The position of stack's maximum value. -1 if the stack is empty.
 */
static long	find_max_pos(t_node *stack)
{
	long	pos;
	int		max;
	t_node	*first;

	pos = 0;
	max = stack->data;
	first = stack;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	stack = first;
	pos = find_pos_in_stack(stack, max);
	return (pos);
}

/**
 * @brief Calculates the number of instructions needed to put
 * a given value, at a given position, to the top of the stack.
 * @param pos Position in the stack of the value to put on top.
 * @param lstsize Stack's size.
 * @param a Binary indicating if the stack is a (1) or not (0).
 * @returns Structure containing the number and type of instructions needed.
 */
static t_cost	to_top(long pos, long lstsize, char a)
{
	t_cost	cost;

	if (pos > lstsize / 2)
	{
		cost.times_f = lstsize - pos;
		if (a == 1)
			cost.ins_f = RRA;
		else
			cost.ins_f = RRB;
	}
	else
	{
		cost.times_f = pos;
		if (a == 1)
			cost.ins_f = RA;
		else
			cost.ins_f = RB;
	}
	return (cost);
}

/**
 * @brief Finds the closest smallest value's position in stack B,
 * for a given value in stack A.
 * @param value Value for which to find the closest smallest value's position.
 * @param stack_b Pointer to the first node of stack_b.
 * @returns The position of the closest smallest value's in stack B.
 * If there is none, returns the position of the max's value.
 */
long	find_closest_pos_b(int value, t_node *stack_b)
{
	long	diff;
	t_node	*first;
	long	pos;
	long	closest;

	if (!stack_b) // necessaire?
		return (-1);
	diff = LONG_MAX;
	closest = LONG_MAX;
	pos = 0;
	first = stack_b;
	while (stack_b)
	{
		if (value > stack_b->data && value - stack_b->data < diff)
		{
			closest = stack_b->data;
			diff = value - stack_b->data;
		}
		stack_b = stack_b->next;
	}
	stack_b = first;
	pos = find_pos_in_stack(stack_b, closest);
	if (pos == -1)
		pos = find_max_pos(stack_b);
	return (pos);
}

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/*else if necessaire ? ds ts les cas, times == times donc 0 pour ins_s*/
static t_cost	new_reverse(t_cost a, t_cost b)
{
	t_cost	final;

	final.ins_f = RR;
	final.times_f = min(a.times_f, b.times_f);
	if (a.times_f > b.times_f)
	{
		final.ins_s = RA;
		final.times_s = a.times_f - b.times_f;
	}
	else if (a.times_f < b.times_f)
	{
		final.ins_s = RB;
		final.times_s = b.times_f - a.times_f;
	}
	else
		final.times_s = 0;
	return (final);
}

static t_cost	new_reverse_rotate(t_cost a, t_cost b)
{
	t_cost	final;

	final.ins_f = RRR;
	final.times_f = min(a.times_f, b.times_f);
	if (a.times_f > b.times_f)
	{
		final.ins_s = RRA;
		final.times_s = a.times_f - b.times_f;
	}
	else if (a.times_f < b.times_f)
	{
		final.ins_s = RRB;
		final.times_s = b.times_f - a.times_f;
	}
	else
		final.times_s = 0;
	return (final);
}

void	set(t_cost *cost)
{
	cost->error = 0;
	cost->ins_f = 0;
	cost->ins_s = 0;
	cost->times_f = 0;
	cost->times_s = 0;
}

// protection ? pos et lstsize?
// Attention au segfault si des valeurs ne sont pas init (normalement ok)
static t_cost	find_cost(t_node *a, t_node *b, long pos_a, long lstsize)
{
	t_cost	cost_a;
	t_cost	cost_b;
	t_cost	final;

	set(&cost_a);
	set(&cost_b);
	set(&final);
	cost_a = to_top(pos_a, lstsize, 1);
	cost_b = to_top(find_closest_pos_b(a->data, b), ft_lstsize(b), 0);
	// printf("dddd %d %d ", cost_a.ins_f, cost_a.times_f);
	// printf("%d %d\n", cost_b.ins_f, cost_b.times_f);
	if (cost_a.ins_f == RA && cost_b.ins_f == RB)
	{
		final = new_reverse(cost_a, cost_b);
		// printf("final %d %d ", final.ins_f, final.times_f);
		// printf("final2 %d %d \n", final.ins_s, final.times_s);
	}
	else if (cost_a.ins_f == RRA && cost_b.ins_f == RRB)
	{
		final = new_reverse_rotate(cost_a, cost_b);
		// printf("final %d %d ", final.ins_f, final.times_f);
		// printf("final2 %d %d \n", final.ins_s, final.times_s);
	}
	else
	{
		final.ins_f = cost_a.ins_f;
		final.ins_s = cost_b.ins_f;
		final.times_f = cost_a.times_f;
		final.times_s = cost_b.times_f;
	}
	return (final);
}

t_cost	find_smallest_cost(t_node *stack_a, t_node *stack_b)
{
	t_cost smallest;
	t_cost tmp;
	long pos_a;
	long lstsize_a;

	if (!stack_a || !stack_b)
		return (smallest.error = 1, smallest);
	pos_a = 1;
	lstsize_a = ft_lstsize(stack_a);
	smallest = find_cost(stack_a, stack_b, 0, lstsize_a);
	stack_a = stack_a->next;
	while (stack_a)
	{
		tmp = find_cost(stack_a, stack_b, pos_a, lstsize_a);
		if ((tmp.times_f + tmp.times_s) < smallest.times_f + smallest.times_s)
			smallest = tmp;
		stack_a = stack_a->next;
		pos_a++;
	}
	return (smallest);
}