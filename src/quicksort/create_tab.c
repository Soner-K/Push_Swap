/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:34:07 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/11 14:52:50 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*create_tab(int ac, char **av)
{
	int		*tab;
	int		i;
	char	**new_av;

	new_av = ft_split(to_string(ac, av), ' ');
	if (!new_av || !new_av[0])
		return (NULL); //exit?
	if (ac == 1 || error(new_av))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	tab = (int *) malloc(sizeof(int) * len_tab(new_av));
	if (!tab)
		return (clear(new_av), NULL);
	i = 0;
	while (new_av[i])
	{
		tab[i] = ft_atol(new_av[i]);
		i++;
	}
	return (clear(new_av), tab);
}

// int main(int ac, char **av)
// {
// 	int *tab;
// 	int i;
//
// 	tab = create_tab(ac, av);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }