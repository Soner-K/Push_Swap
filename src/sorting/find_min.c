/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:56:20 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/12 17:20:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_min	find_min(t_node *lst, int *sorted)
{
	t_min	min;
	int		size;

	size = 0;
	min.value = sorted[0];
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
