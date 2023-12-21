/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:28:23 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/21 14:16:08 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

d_node	*ft_lstnew(int data)
{
	d_node	*new;

	new = malloc(sizeof(d_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_node(d_node **node, d_node *insert)
{
	if (!(*node) || !insert)
		return ;
	insert->next = (*node)->next;
	(*node)->next = insert;
	insert->prev = (*node);
}

void	clear_list(d_node **node) // incorporer un free en parcourant prev?
{
	d_node	*tmp;

	if (!node)
		return ;
	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		(*node) = tmp;
	}
}
