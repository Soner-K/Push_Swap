/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:24:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/22 14:25:26 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	find_pos(t_node *lst, int value)
{
	long	i;

	i = 0;
	while (lst)
	{
		if (lst->data == value)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}