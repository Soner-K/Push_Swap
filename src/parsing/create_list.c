/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:11:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/29 18:44:18 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char ft_isdigit(char **strs)
{
	int	i;
	int	j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (strs[i])
	{
		while (strs[i][j])
		{
			if (strs[i][j] == 34)
				count++;
			j++;
		}
		i++;
		j = 0;
		if (!count % 2 && count != 0)
			return (0);
		count = 0;
	}
	return (1);
}

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

	if (!ft_isdigit(av))
		ft_quit();
	strs = ft_split((to_string(ac, av)), ' ');
	if (!strs || ft_error(strs) || !ft_strlen(strs[0]))
		ft_quit();
	if (!strs[0])
		return (ft_clear(strs), NULL);
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
	return (lst->next = NULL, ft_clear(strs), first);
}
