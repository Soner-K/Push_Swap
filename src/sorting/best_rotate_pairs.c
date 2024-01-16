/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotate_pairs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:52:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/16 14:56:49 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	*best_rotate_pairs(t_node *lst, t_pairs pairs)
{
	int	lstsize;
	int	*tab;
	int	index_min;
	
	lstsize = ft_lstsize(lst);
	tab = malloc(sizeof(int) * 4);
	if (!tab)
		return (NULL);
	tab[3] = 0;
	index_min = min(pairs.pos_first, pairs.pos_second);
	if (pairs.gap > lstsize / 2)
		tab[0] = 
	
}