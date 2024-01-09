/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:18 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/09 19:51:40 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_lstadd_front(d_node **lst, d_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->prev = NULL;// nécessaire ?
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}
