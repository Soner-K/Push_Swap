/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:30:08 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/12 13:15:33 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*As the name suggests, this functions's goal
is to store all the strings of a char **(in this case
av) inside one string only*/
char	*to_string(int ac, char **av)
{
	char	*str;
	// int		i = 0;
	
	str = NULL;
	// av++;
	// printf("ac = %d\n", ac);
	// while (av[i])
	// {
	// 	printf("av[%d] = %s\n", i, av[i]);
	// 	i++;	
	// }
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
