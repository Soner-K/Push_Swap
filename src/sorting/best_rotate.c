/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:34:57 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/23 13:46:35 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Returns, depending on the pos of value, a structure containing
how many times to do an instruction (RRA or RA) to reach the value.*/
t_ins	best_rotate(t_node *lst, int value)
{
	t_ins		ins;
	long		lstsize;
	long		pos_in_stack;
	
	lstsize = ft_lstsize(lst);
	ins.value = value;
	pos_in_stack = find_pos_in_stack(lst, value);
	if (pos_in_stack > lstsize / 2)
	{
		ins.instruction = RRA;
		ins.times = lstsize - pos_in_stack;
	}
	else
	{
		ins.instruction = RA;
		ins.times = pos_in_stack;
	}
	return (ins);
}
