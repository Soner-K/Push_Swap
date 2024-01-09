/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:08:59 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/09 19:50:55 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	clear_list(d_node **node)
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
