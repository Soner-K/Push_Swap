/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:29 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/09 19:50:41 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
