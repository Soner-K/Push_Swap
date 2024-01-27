/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:42:00 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 20:00:36 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Finds the maximum's position in a stack.
 * @param stack Pointer to the first node of a stack.
 * @returns The position of stack's maximum value. -1 if the stack is empty.
 */
long	find_max_pos(t_node *stack)
{
	long	pos;
	int		max;
	t_node	*first;

	if (!stack)
		return (-1);
	pos = 0;
	max = stack->data;
	first = stack;
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
 * @brief Finds the minimum's position in a stack.
 * @param stack Pointer to the first node of a stack.
 * @returns The position of stack's minimum value. -1 if the stack is empty
 */
long	find_min_pos(t_node *stack)
{
	long	pos;
	int		min;
	t_node	*first;

	if (!stack)
		return (-1);
	pos = 0;
	min = stack->data;
	first = stack;
	stack = stack->next;
	while (stack)
	{
		if (min > stack->data)
			min = stack->data;
		stack = stack->next;
	}
	stack = first;
	pos = find_pos_in_stack(stack, min);
	return (pos);
}

/**
 * @brief Finds value's position.
 * @param lst Pointer to the first node of a list.
 * @param value Value to look for.
 * @returns The index of the value if it is found. Returns -1 otherwise.
 */
long	find_pos_in_stack(t_node *lst, long value)
{
	long	i;

	if (value == LONG_MAX || !lst)
		return (-1);
	i = 0;
	while (lst)
	{
		if (lst->data == value)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}
