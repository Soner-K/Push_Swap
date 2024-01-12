/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:11:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/12 15:01:36 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Creates the list that will be used later if the arguments are valid,
which is checked by the error function.*/
t_node	*create_list(int ac, char **av, int i)
{
	t_node	*lst;
	char	**strs;
	int		*tab;

	strs = ft_split((to_string(ac, av)), ' ');
	if (!strs || !strs[0])
		return (NULL);
	if (ac == 1 || error(strs))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	lst = ft_lstnew(ft_atol(strs[i++]));
	if (!lst)
		return (NULL);
	tab = create_and_sort(ac, av, len_tab(strs));
	while (strs[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atol(strs[i++])));
		lst->sorted = tab;
		lst = lst->next;
	}
	lst->sorted = tab;
	lst->next = NULL;
	return (clear(strs), ft_lstfirst(lst));
}

// t_node	*create_list(int *tab, size_t size)
// {
// 	size_t	i;
// 	t_node	*lst;
// 	t_node	*first;
//	int		*sorted;
//
// 	i = 0;
// 	lst = ft_lstnew(tab[i++]);
// 	if (!lst)
// 		return (NULL);
// 	first = lst;
// 	while (i < size)
// 	{
// 		ft_lstadd_back(&lst, ft_lstnew(tab[i++]));
// 		if (!(lst->next))
// 			return (NULL);
// 		lst = lst->next;
// 	}
// 	lst->next = NULL;
// 	return (first);
// } pb : initialisation de chaque variable dans le noeud

void	print_tab(int *tab, int size)
{
	while (size--)
	{
		printf("%d ", *tab);
		tab++;
	}
	printf("\n");
}

// int	main(int ac, char **av)
// {
// 	t_node *lst;
	
// 	lst = create_list(ac, av, 0);
// 	if (!lst)
// 		return (0);
// 	print_list(lst, NULL);
// 	clear_list(&lst);
// }