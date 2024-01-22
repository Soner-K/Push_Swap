/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:34:57 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/22 11:04:16 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// t_ins	best(t_node *lst, int *sorted, int last)
// {
// 	static long	index_f;
// 	static long	index_s;
// 	t_ins		ins;
	
// 	index_f = find_index_min(lst, sorted, last);
// 	if (sorted[index_f + 1])
// 		index_s = index_f + 1;
	
	
// }

/* modifier cette fonction en tenant conmpte qu rra = lstsize-index
et ra = index*/
t_ins	find_value(t_node *lst, int value, size_t i)
{
	t_ins		ins;
	t_node		*first;
	size_t		lstsize;
	long		count;
	
	lstsize = ft_lstsize(lst);
	count = 0;
	first = lst;
	while (lst)
	{
		if (lst->data == value)
			break ;
		i++;
		lst = lst->next;
	}
	lst = first;
	if (i > lstsize / 2)
	{
		ins.instruction = RRA;
		count = lstsize;
	}
	else
		ins.instruction = RA;
	while (lst && lst->data != value)
	{
		if (ins.instruction == RRA)
			count--;
		else
			count++;
		lst = lst->next;
	}
	ins.times = count;
	return (ins);
}