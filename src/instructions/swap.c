/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:20:56 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/26 15:37:10 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Swaps the data of the first two nodes of a list.
 * @param stack Address of the stack's first node.
 * @returns Returns 0 if stack's size is strictly less than 2.
 * Otherwise, returns 1 (the operation was successful).
 */
static char	lst_swap(t_node **stack)
{
	int	tmp;

	if (!(*stack) || !(*stack)->next)
		return (0);
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	return (1);
}

void	sa(t_node **stack_a)
{
	if (lst_swap(stack_a))
		ft_putstr("sa\n");
}

void	sb(t_node **stack_b)
{
	if (lst_swap(stack_b))
		ft_putstr("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if (lst_swap(stack_a) && lst_swap(stack_b))
		ft_putstr("ss\n");
}