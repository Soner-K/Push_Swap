/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:20:56 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/24 15:21:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Swaps the first two nodes of a list.
 * @param stack Adress of the stack's first node.
 * @returns void. Doesn't do anything if stack's size is strictly less than 2.
 */
static void	lst_swap(t_node **stack)
{
	int	tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

void	sa(t_node **stack_a)
{
	lst_swap(stack_a);
	ft_putstr("sa\n");
}

void	sb(t_node **stack_b)
{
	lst_swap(stack_b);
	ft_putstr("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	lst_swap(stack_a);
	lst_swap(stack_b);
	ft_putstr("ss\n");
}