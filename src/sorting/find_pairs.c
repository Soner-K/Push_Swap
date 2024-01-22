/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pairs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:10:22 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/22 13:49:29 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Returns a pairs structure, with the gap separating the two next
min values.*/
static int	ft_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

static int	*set(t_node *lst, int *sorted, int last)
{
	int	*tab;
	int	index_first;

	tab = malloc(sizeof(int) * 2);
	if (!tab)
		return (NULL);
	index_first = find_index_min(lst, sorted, last);
	tab[0] = sorted[index_first];
	tab[1] = sorted[index_first + 1]; // depassement de tableau?
	return (tab);
}

t_pairs	find_pairs(t_node *lst, int *sorted, int last)
{
	t_pairs	pairs;
	int		*tab;
	int		i;

	tab = set(lst, sorted, last);
	// if (!tab)
	// 	return (pairs); //gerer erreur.
	pairs.pos_first = -1;
	pairs.pos_second = -1;
	pairs.first = tab[0];
	pairs.second = tab[1];
	pairs.gap = -1;
	i = 0;
	while (lst)
	{
		if (lst->data == pairs.first)
			pairs.pos_first = i;
		else if (lst->data == pairs.second)
			pairs.pos_second = i;
		i++;
		lst = lst->next;
	}
	if (pairs.pos_first > -1 && pairs.pos_second > -1)
		pairs.gap = ft_abs(pairs.pos_first - pairs.pos_second); 
		/*pb en cas derreur de un mais pas de l'autre et negatif*/
	return (free(tab), pairs);
}
