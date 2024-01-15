/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:18 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/15 14:51:40 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	find_index(t_node *lst, int *sorted, int last)
{
	long	i;
	t_node	*first;
	
	if (!lst || !sorted)
		return (-1);
	i = 0;
	first = lst;
	while (sorted[i] != last)
	{
		if (lst->data == sorted[i])
			return (i);
		lst = lst->next;
		if (!lst)
		{
			lst = first;
			i++;
		}
	}
	return (-1);
}

// int main(int ac, char **av)
// {
// 	t_node	*lst;
	
// 	lst = create_list(ac, av, 0);
// 	printf("%zu\n", find_index(lst, lst->sorted, lst->sorted[9]));
// }