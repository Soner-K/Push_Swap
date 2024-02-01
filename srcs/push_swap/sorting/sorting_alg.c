/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:10:16 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 14:51:16 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Finds the best instructions for pushing a value at the right
 * position, in stack A. Does the instructions and then pushes the value to A.
 * @param a Adress of the pointer to stack A's first node.
 * @param b Adress of the pointer to stack B's first node.
 * @param sizes A structure containing the sizes of stack A and B.
 * @returns void.
 */
static void	push_to_a(t_node **a, t_node **b, t_sizes *sizes)
{
	t_cost	set;

	set = smallest_cost_to_a(*a, *sizes, (*b)->data);
	if (*a && *b)
		do_it_first(a, b, set);
	if (*a && *b)
		do_it_second(a, b, set);
	pa(a, b, 1);
	sizes->lstsize_a++;
	sizes->lstsize_b--;
}

/**
 * @brief Finds the best instructions for pushing a value at the right
 * position, in stack B. Does the instructions and then pushes the value to B.
 * @param a Adress of the pointer to stack A's first node.
 * @param b Adress of the pointer to stack B's first node.
 * @param sizes A structure containing the sizes of stack A and B.
 * @returns void.
 */
static void	push_to_b(t_node **a, t_node **b, t_sizes *sizes)
{
	t_cost	set;

	set = smallest_cost_to_b(*a, *b, *sizes);
	if (*a && *b)
		do_it_first(a, b, set);
	if (*a && *b)
		do_it_second(a, b, set);
	pb(b, a, 1);
	sizes->lstsize_a--;
	sizes->lstsize_b++;
}

/**
 * @brief Puts the minimum value in stack A to the top.
 * @param a Adress of the pointer to stack A's first node.
 * @param sizes A structure containing the sizes of stack A and B.
 * @returns void.
 */
static void	put_min_at_top(t_node **a, t_sizes sizes)
{
	long	pos_min;
	t_cost	ins;

	pos_min = find_min_pos(*a);
	ins = to_top(pos_min, sizes.lstsize_a, 1);
	do_it_first(a, NULL, ins);
}

/**
 * @brief Checks if a stack is sorted.
 * @param stack Pointer to the first node of a stack.
 * @returns 0 if not sorted, 1 otherwise.
 */
char	is_sorted(t_node *stack)
{
	while (stack)
	{
		if (stack->next && stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * @brief Sorts stack A, using an empty stack (b)
 * and a given set of instructions.
 * @param a Adress of the pointer to stack A's first node.
 * @param b Adress of the pointer to stack B's first node.
 * @param sizes A structure containing the sizes of stack A and B.
 * @returns void.
 */
void	sort(t_node **a, t_node **b, t_sizes *sizes)
{
	if (sizes->lstsize_a > 4)
	{
		pb(b, a, 1);
		pb(b, a, 1);
		sizes->lstsize_a -= 2;
		sizes->lstsize_b = 2;
	}
	while (sizes->lstsize_a > 3 && !is_sorted(*a))
		push_to_b(a, b, sizes);
	sort_for_three(a);
	while (ft_lstsize(*b) != 0)
		push_to_a(a, b, sizes);
	put_min_at_top(a, *sizes);
}
