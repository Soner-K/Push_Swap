/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/09 19:51:34 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_fuse(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j])
			new[i++] = s2[j++];
	new[i] = 0;
	free(s1);
	return (new);
}
