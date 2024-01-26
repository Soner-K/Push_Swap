/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_in_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:24:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/26 16:10:22 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Finds value's pos in stack. If value isn't found, returns -1.*/
long	find_pos_in_stack(t_node *lst, long value)
{
	long	i;

	if (value == LONG_MAX)
		return (-1);
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