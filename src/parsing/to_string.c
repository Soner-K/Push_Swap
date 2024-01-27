/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:30:08 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 20:57:54 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Puts an array of strings into a string.
 * @param ac The number of parameters given in the command line.
 * @param av An array of strings containing the command line's parameters.
 * @returns A string containing all the strings in av, separated by a space.
 */
char	*to_string(int ac, char **av)
{
	char	*str;

	str = NULL;
	if (!av || ac == 1)
		return (NULL);
	ac--;
	av++;
	while (ac--)
	{
		str = ft_fuse(str, *av++);
		str = ft_fuse(str, " ");
	}
	return (str);
}
