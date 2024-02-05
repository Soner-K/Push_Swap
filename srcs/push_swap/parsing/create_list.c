/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:11:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/02/05 11:41:45 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	free_and_quit(char **strs)
{
	ft_clear(strs);
	ft_quit();
}

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
	if (!strs || ft_error(strs))
		ft_quit();
	if (!strs[0])
		return (ft_clear(strs), ft_quit(), NULL);
	lst = ft_lstnew(ft_atol(strs[i++]));
	if (!lst)
		free_and_quit(strs);
	first = lst;
	while (strs[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atol(strs[i++])));
		lst = lst->next;
		if (!lst && strs[i])
		{
			clear_list(&first);
			free_and_quit(strs);
		}
	}
	return (ft_clear(strs), first);
}
