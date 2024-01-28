/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_cost_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:58:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/28 14:13:05 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set(t_cost *cost)
{
	cost->error = 0;
	cost->ins_f = 0;
	cost->ins_s = 0;
	cost->times_f = 0;
	cost->times_s = 0;
}

// protection ? pos et lstsize?
// Attention au segfault si des valeurs ne sont pas init (normalement ok)
/**
 * @brief Finds the cost (i.e which instruction to do and how many times)
 * for each node in stack A.
 * @param b Pointer to stack B's first node.
 * @param data_a The value for which to find the cost in stack A.
 * @param pos_a The position of data_a in stack A.
 * @param sizes A structure containing stack a's and stack b's sizes.
 * @returns The cheapest cost for data_a.
 */
static t_cost	find_cost(t_node *b, long data_a, long pos_a, t_sizes sizes)
{
	t_cost	cost_a;
	t_cost	cost_b;
	t_cost	final;

	set(&cost_a);
	set(&cost_b);
	set(&final);
	cost_a = to_top(pos_a, sizes.lstsize_a, 1);
	cost_b = to_top(closest_smallest_in_b(data_a, b), sizes.lstsize_b, 0);
	if (cost_a.ins_f == RA && cost_b.ins_f == RB)
		final = new_rotate(cost_a, cost_b);
	else if (cost_a.ins_f == RRA && cost_b.ins_f == RRB)
		final = new_reverse_rotate(cost_a, cost_b);
	else
	{
		final.ins_f = cost_a.ins_f;
		final.ins_s = cost_b.ins_f;
		final.times_f = cost_a.times_f;
		final.times_s = cost_b.times_f;
	}
	return (final);
}

/**
 * @brief Finds the closest smallest value's position in stack B,
 * for a given value in stack A.
 * @param value Value for which to find the closest smallest value's position.
 * @param stack_b Pointer to stack B's first node.
 * @returns The position of the closest smallest value's in stack B.
 * If there is none, returns the position of the max's value.
 */
static long	closest_smallest_in_b(int value, t_node *stack_b)
{
	long	diff;
	t_node	*first;
	long	pos;
	long	closest;

	if (!stack_b)
		return (-1);
	diff = LONG_MAX;
	closest = LONG_MAX;
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

/**
 * @brief Finds the smallest set of instruction(s) to place a value in stack B,
 * right before its target value (closest smallest).
 * @param stack_a Pointer to stack A's first node.
 * @param stack_b Pointer to stack B's first node.
 * @param sizes A structure containing the sizes of stack A and B.
 * @returns The smallest set of instruction(s). Returns error if set not found.
 */
t_cost	smallest_cost_to_b(t_node *a, t_node *b, t_sizes sizes)
{
	long	pos_a;
	t_cost	smallest;
	t_cost	tmp;

	if (!a || !b)
		return (smallest.error = 1, smallest);
	pos_a = 1;
	smallest = find_cost(b, a->data, 0, sizes);
	a = a->next;
	while (a)
	{
		if (smallest.times_f + smallest.times_s == 1)
			break ;
		tmp = find_cost(b, a->data, pos_a, sizes);
		if ((tmp.times_f + tmp.times_s) < smallest.times_f + smallest.times_s)
			smallest = tmp;
		a = a->next;
		pos_a++;
	}
	return (smallest);
}
