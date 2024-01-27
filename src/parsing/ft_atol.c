/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:31:00 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 20:37:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Transforms a string into a long int.
 * @param nptr The string to transform into an array.
 * @returns The long int resulting in the transofrmation.
 * If the conversion failed, returns 0 (NO_CONVERSION).
 */
long	ft_atol(const char *nptr)
{
	long	num;
	int		i;
	char	sign;

	num = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += (int)(nptr[i] - '0');
		i++;
	}
	if (i == 0)
		return (NO_CONVERSION);
	return (num * sign);
}
