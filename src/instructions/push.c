/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:12:52 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/28 17:54:45 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Pushes the top element of push's stack into store's stack.
 * @param store The address of the first node of the stack
 * to which the node will be pushed.
 * @param push The address of the first node of the stack
 * from which the node will be pushed.
 * @returns  Returns 0 if there is no node in push.
 * Returns 1 otherwise (the operation was successful).
 */
char	lst_push(t_node **store, t_node **push)
{
	t_node	*tmp;

	if (!(*push))
		return (0);
	tmp = *push;
	*push = (*push)->next;
	if (*push)
		(*push)->prev = NULL;
	ft_lstadd_front(store, tmp);
	return (1);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (lst_push(stack_a, stack_b))
		ft_putstr("pa\n", 1);
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	if (lst_push(stack_b, stack_a))
		ft_putstr("pb\n", 1);
}
