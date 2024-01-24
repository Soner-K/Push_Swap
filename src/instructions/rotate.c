/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:01 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/24 15:12:42 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Shift up all the nodes once. The first node becomes
 * the last node in the stack.
 * @param stack Adress of the first node of stack.
 * @returns void. If there is no element in first, nothing is done.
 */
static void	lst_rotate(t_node **stack)
{
	t_node *first;

	if (!(*stack))
		return ;
	first = *stack;
	ft_lstadd_back(stack, first);
	(*stack) = (*stack)->next;
	first->next = NULL;
}

void	ra(t_node **first_a)
{
	lst_rotate(first_a);
	ft_putstr("ra\n");
}

void	rb(t_node **first_b)
{
	lst_rotate(first_b);
	ft_putstr("rb\n");
}

void	rr(t_node **first_a, t_node **first_b)
{
	lst_rotate(first_a);
	lst_rotate(first_b);
	ft_putstr("rr\n");
}