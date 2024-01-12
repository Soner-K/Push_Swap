/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:16:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/12 15:05:09 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*create_and_sort(int ac, char **av, int size)
{
	int	*tab;
	
	tab = create_tab(ac, av, &size);
	if (!tab)
		exit(1);
	quicksort(tab, 0, size - 1);
	return (tab);
}
