/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_cost_to_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:27:36 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 19:32:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Finds the closest biggest value's position in stack A,
 * for a given value in stack B.
 * @param value Value for which to find the closest biggest value's position.
 * @param stack_a Pointer to stack A's first node.
 * @returns The position of the closest biggest value's in stack B.
 * If there is none, returns the position of the max's value.
 */
long	closest_biggest_in_a(int value, t_node *stack_a)
{
	long	diff;
	long	pos;
	long	closest;
	t_node	*first;

	if (!stack_a)
		return (-1);
	diff = LONG_MAX;
	closest = LONG_MAX;
	pos = 0;
	first = stack_a;
	while (stack_a)
	{
		if (value < stack_a->data && stack_a->data - value < diff)
		{
			closest = stack_a->data;
			diff = stack_a->data - value;
		}
		stack_a = stack_a->next;
	}
	stack_a = first;
	pos = find_pos_in_stack(stack_a, closest);
	if (pos == -1)
		pos = find_min_pos(stack_a);
	return (pos);
}

/**
 * @brief Finds the smallest set of instruction to place a value in stack A,
 * right before its target value (closest_biggest).
 * @param stack_a Pointer to stack A's first node.
 * @param sizes A structure containing the sizes of stack A and B.
 * @param value The value (in stack B) to be put before the target value.
 * @returns
 */
t_cost	smallest_cost_to_a(t_node *stack_a, t_sizes sizes, long value)
{
	t_cost	final;
	long	pos_a;

	pos_a = closest_biggest_in_a(value, stack_a);
	final = to_top(pos_a, sizes.lstsize_a, 1);
	return (final);
}
