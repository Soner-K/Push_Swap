/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:31:19 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/12 12:31:22 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Checks if there's any error like no valid numbers.*/
char	error(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab[i])
	{
		if (ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN
			|| (ft_atol(tab[i]) == NO_CONVERSION && tab[i][0] != '0'))
			return (clear(tab), 1);
		while (tab[j])
		{
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
				return (clear(tab), 1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
