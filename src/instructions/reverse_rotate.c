/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:19:45 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/26 15:37:05 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Shifts down all the stack's nodes once.
 * The last node becomes the first.
 * @param stack Address of the stack's first node.
 * @returns Returns 0 if stack's size is strictly less than 2.
 * Returns 1 otherwise (the operation was successful).
 */
static char	lst_reverse_rotate(t_node **stack)
{
	t_node	*last_prev;

	if (!(*stack) || !(*stack)->next)
		return (0);
	last_prev = ft_lstlast(*stack)->prev;
	ft_lstadd_front(stack, ft_lstlast(*stack));
	last_prev->next = NULL;
	return (1);
}

void	rra(t_node **first_a)
{
	if (lst_reverse_rotate(first_a))
		ft_putstr("rra\n");
}

void	rrb(t_node **first_b)
{
	if (lst_reverse_rotate(first_b))
		ft_putstr("rrb\n");
}

void	rrr(t_node **first_a, t_node **first_b)
{
	if (lst_reverse_rotate(first_a) && lst_reverse_rotate(first_b))
		ft_putstr("rrr\n");
}