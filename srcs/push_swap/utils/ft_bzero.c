/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:31:12 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 14:51:35 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*one_b;

	if (s == NULL && n == 0)
		return ;
	one_b = s;
	while (n--)
	{
		*one_b = 0;
		one_b++;
	}
}
