/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:11:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 21:34:57 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Creates a stack, using the arguments given in the command line.
 * @param ac The number of arguments given in the command line.
 * @param av An array of array containing the arguments given
 * in the commande line.
 * @param i An argument used for iterating through an array.
 * @returns The created stack. Nothing is returned in case of an error
 * (error in the parameters or in the allocation of memory).
 */
t_node	*create_list(int ac, char **av, int i)
{
	t_node	*lst;
	t_node	*first;
	char	**strs;

	strs = ft_split((to_string(ac, av)), ' ');
	if (!strs || !strs[0] || ac == 1 || error(strs))
		ft_quit();
	lst = ft_lstnew(ft_atol(strs[i++]));
	if (!lst)
	{
		clear(strs);
		ft_quit();
	}
	first = lst;
	while (strs[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atol(strs[i++])));
		lst = lst->next;
	}
	lst->next = NULL;
	lst = first;
	clear(strs);
	return (lst);
}
