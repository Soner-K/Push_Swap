/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:34:57 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/23 13:21:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* modifier cette fonction en tenant conmpte qu rra = lstsize-index
et ra = index*/
// t_ins	find_value(t_node *lst, int value, size_t i)
// {
// 	t_ins		ins;
// 	t_node		*first;
// 	size_t		lstsize;
// 	long		count;
	
// 	lstsize = ft_lstsize(lst);
// 	count = 0;
// 	ins.value = value;
// 	first = lst;
// 	while (lst)
// 	{
// 		if (lst->data == value)
// 			break ;
// 		i++;
// 		lst = lst->next;
// 	}
// 	lst = first;
// 	if (i > lstsize / 2)
// 	{
// 		ins.instruction = RRA;
// 		count = lstsize;
// 	}
// 	else
// 		ins.instruction = RA;
// 	while (lst && lst->data != value)
// 	{
// 		if (ins.instruction == RRA)
// 			count--;
// 		else
// 			count++;
// 		lst = lst->next;
// 	}
// 	ins.times = count;
// 	return (ins);
// }

t_ins	find_value(t_node *lst, int value, size_t i)
{
	t_ins		ins;
	size_t		lstsize;
	
	lstsize = ft_lstsize(lst);
	ins.value = value;
	while (lst)
	{
		if (lst->data == value)
			break ;
		i++;
		lst = lst->next;
	}
	if (i > lstsize / 2)
	{
		ins.instruction = RRA;
		ins.times = lstsize - i;
	}
	else
	{
		ins.instruction = RA;
		ins.times = i;
	}
	return (ins);
}