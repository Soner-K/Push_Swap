/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:29:11 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/23 15:42:22 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the first two elements at the top of the stack A.*/
void	sa(d_node **first_a)
{
	int	tmp;

	if (!(*first_a) || !(*first_a)->next)
		return ;
	tmp = (*first_a)->data;
	(*first_a)->data = (*first_a)->next->data;
	(*first_a)->next->data = tmp;
}

/*Pushes the top element of B's stack (push) to the top of A's stack (store).*/
void	pa(d_node **store, d_node **push)
{
	d_node	*new_first;
	d_node	*tmp;

	if (!(*push))
		return ;
	new_first = ft_lstnew((*push)->data);
	if (!new_first)
		return ;
	new_first->next = *store;
	new_first->prev = NULL;
	*store = new_first;
	tmp = *push;
	*push = (*push)->next;
	free(tmp);
}

/*Shift up all the nodes of stack B once. It can be done by simply placing
the first node to the last position of the stack.*/
void	ra(d_node **first_node)
{
	if (!(*first_node))
		return ;
	(*first_node)->prev = ft_lstlast(*first_node);
	ft_lstlast(*first_node)->next = *first_node;
	(*first_node)->next = NULL;
}

/*Shift down all the nodes of stack A once. */
void	rra(d_node **first_node)
{
	d_node	*last;
	d_node	*last_prev;
	
	if (!(*first_node))
		return ;
	last = ft_lstlast(*first_node);
	last_prev = ft_lstlast(*first_node)->prev;
	last_prev->next = NULL;
	last->next = (*first_node);
	*first_node = last;
	last->prev = NULL;
}
