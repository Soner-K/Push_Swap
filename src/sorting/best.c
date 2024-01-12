/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:01:20 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/12 17:34:03 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*GERER LES PA ET PB ET LEUR IMPACT SUR SORTED*/

static void	check_mode(t_node *lst, char *mode, t_min *min)
{
	if (!mode)
		return ;
	if (!ft_strcmp("next_min", mode))
		*min = find_next_min(lst);
	else
		*min = find_min(lst, lst->sorted);
}

int	*best(t_node *lst, char *mode) // proteger pour !lst?
{
	int *tab;
	size_t lstsize;
	int	count;
	t_min min;

	tab = malloc(sizeof(int) * 3);
	if (!tab)
		return (NULL);
	tab[2] = 0;
	lstsize = ft_lstsize(lst);
	count = 0;
	check_mode(lst, mode, &min);
	if (min.gap > lstsize / 2)
	{
		tab[0] = RRA;
		count = lstsize;
	}
	else
		tab[0] = RA;
	while (lst && lst->data != min.value)
	{
		if (tab[0] == RRA)
			count--;
		else
			count++;
		lst = lst->next;
	}
	tab[1] = count;
	return (tab);
}

int main(int ac, char **av)
{
	play(ac, av);
}