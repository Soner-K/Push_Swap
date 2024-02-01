/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:31:19 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 14:50:30 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static char	only_digits(char *str)
{
	short int	i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[1])
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Checks if there is any error in the array of strings that will
 * be used for creating the stack.
 * @param tab A pointer to an array of strings.
 * @returns 1 if there is an error in the array, 0 otherwise.
 */
char	ft_error(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab[i])
	{
		if (ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN
			|| (ft_atol(tab[i]) == NO_CONVERSION && tab[i][0] != '-')
			|| !only_digits(tab[i]))
			return (ft_clear(tab), 1);
		while (tab[j])
		{
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
				return (ft_clear(tab), 1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
