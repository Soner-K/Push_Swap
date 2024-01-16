/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:51:05 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/16 11:48:39 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Compares the first node's value and find the next lowest value
and the gap separating the two.*/
t_min	find_next_min(t_node *lst)
{
	t_min	min;

	min.value = lst->data;
	min.gap = 0;
	while (lst)
	{
		if (min.value > lst->data)
		{
			min.value = lst->data;
			return (min);
		}
		min.gap++;
		lst = lst->next;
	}
	min.gap = 0;
	return (min);
}

// int	main(int ac, char **av)
// {
// 	t_node *lst;
// 	t_min min;

// 	lst = create_list(ac, av);
// 	if (!lst)
// 		return (1);
// 	min = find_next_min(lst);
// 	printf("Actual data : %d\nNext min is %d\nDistance between the two %ld\n",
// 		lst->data, min.value, min.gap);
// }