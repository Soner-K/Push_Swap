/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:29 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/28 13:17:35 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*ft_lstnew(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_quit(NULL, NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
