/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:31:00 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/12 12:31:02 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Transforming a string into a long, so that I can check later
if the value returned is bigger/smaller than INT_MAX/INT_MIN.*/
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
