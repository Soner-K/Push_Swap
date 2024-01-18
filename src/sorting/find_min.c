/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:56:20 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/18 14:18:40 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Find the minimum value of the stack, using the sorted tab.
Find_index is used to know which value to look for (since the
stack's size, and therefore its values, will change during the algorithm)*/
t_min	find_min(t_node *lst, int *sorted, int size)
{
	t_min	min;
	long	index_min;

	index_min = find_index_min(lst, sorted, sorted[size - 1]);
	if (index_min == -1)
		return (min.gap = -1, min.value = -1, min);
	min.value = sorted[index_min];
	min.gap = 0;
	while (lst)
	{
		if (min.value == lst->data)
			return (min);
		min.gap++;
		lst = lst->next;
	}
	return (min);
}

// int	main(int ac, char **av)
// {
// 	t_node *lst;
// 	t_min min;
//
// 	lst = create_list(ac, av, 0);
// 	if (!lst)
// 		return (1);
// 	min = find_min(lst);
// 	printf("Actual data : %d\nAbs min is %d\nDistance between the two %ld\n",
// 		lst->data, min.value, min.gap);
// 	clear_list(&lst);
// }
