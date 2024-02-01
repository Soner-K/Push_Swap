/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:01 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 14:50:07 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Shifts up all the nodes once. The first node becomes
 * the last node in the stack.
 * @param stack Address of the first node of stack.
 * @returns If there is no element in first, returns 0.
 * Returns 1 otherwise (the operation was successful).
 */
char	lst_rotate(t_node **stack)
{
	t_node	*first;

	if (!(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	ft_lstadd_back(stack, first);
	(*stack) = (*stack)->next;
	first->next = NULL;
	return (1);
}

void	ra(t_node **first_a, char show)
{
	if (lst_rotate(first_a))
		if (show == 1)
			ft_putstr("ra\n", 1);
}

void	rb(t_node **first_b, char show)
{
	if (lst_rotate(first_b))
		if (show == 1)
			ft_putstr("rb\n", 1);
}

void	rr(t_node **first_a, t_node **first_b, char show)
{
	if (!(*first_a) || !(*first_a)->next || !(*first_b) || !(*first_b)->next)
		return ;
	if (lst_rotate(first_a) && lst_rotate(first_b))
		if (show == 1)
			ft_putstr("rr\n", 1);
}
