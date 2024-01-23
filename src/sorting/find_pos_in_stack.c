/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:24:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/23 13:21:59 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	find_pos_in_stack(t_node *lst, int value)
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