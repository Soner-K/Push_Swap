/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:13:26 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/11 14:27:45 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	binary_search(int *tab, int right, int value)
{
	int	left;
	int	med;

	left = 0;
	while (right >= left)
	{
		med = left + (right - left) / 2;
		if (tab[med] == value)
			return (med);
		else if (tab[med] < value)
			left = med + 1;
		else
			right = med - 1;
	}
	return (-1);
}

// int	main(int ac, char **av)
// {
// 	int *tab;
// 	int i;

// 	tab = create_tab(ac, av);
// 	ac--;
// 	i = 0;
// 	quicksort(tab, 0, ac - 1);
// 	while (i < ac)
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	printf("Indice de la valeur %ld = %d\n", ft_atol(av[4]), binary_search(tab,
// 			ac - 1, ft_atol(av[4])));
// }