/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:29:11 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/11 15:36:56 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Swaps the first two elements at the top of the stack A.*/
void	sa(t_node **first_a)
{
	int	tmp;

	if (!(*first_a) || !(*first_a)->next)
		return ;
	tmp = (*first_a)->data;
	(*first_a)->data = (*first_a)->next->data;
	(*first_a)->next->data = tmp;
}

/*Pushes the top element of B's stack (push) to the top of A's stack (store).*/
void	pa(t_node **store, t_node **push)
{
	t_node	*tmp;

	if (!(*push))
		return ;
	tmp = *push;
	*push = (*push)->next;
	if (*push)
		(*push)->prev = NULL;
	ft_lstadd_front(store, tmp);
}

/*Shift up all the nodes of stack B once. It can be done by simply placing
the first node to the last position of the stack.*/
void	ra(t_node **first_node)
{
	t_node	*first;

	if (!(*first_node))
		return ;
	first = *first_node;
	ft_lstadd_back(first_node, first);
	(*first_node) = (*first_node)->next;
	first->next = NULL;
}

/*Shift down all the nodes of stack A once. It can be done by simply placing
the last node to the first position of the stack.*/
void	rra(t_node **first_node)
{
	t_node	*last_prev;

	if (!(*first_node) || !(*first_node)->next)
		return ;
	last_prev = ft_lstlast(*first_node)->prev;
	ft_lstadd_front(first_node, ft_lstlast(*first_node));
	last_prev->next = NULL;
}
