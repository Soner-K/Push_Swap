/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:39:34 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/18 14:52:44 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	max(int a, int b, char *changed)
{
	if (a > b)
	{
		*changed = 1;
		return (a);
	}
	*changed = 0;
	return (b);
}