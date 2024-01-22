/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotate_pairs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:52:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/22 14:01:01 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Allows to check which value is closer to the top of the list,
accounting for the fact that we can go upward or backward.*/
static int	min_count(int lstsize, t_ins *ins, t_pairs pairs)
{
	int	absolute_min;
	int	count_abs_min;
	int	absolute_max;
	int	count_abs_max;

	absolute_min = min(pairs.pos_first, pairs.pos_second);
	count_abs_min = 0;
	absolute_max = max(pairs.pos_first, pairs.pos_second, 0);
	count_abs_max = 0;
	while (absolute_min--)
		count_abs_min++;
	while (absolute_max != lstsize)
	{
		absolute_max++;
		count_abs_max++;
	}
	if (count_abs_min > count_abs_max)
		ins->instruction = RRA;
	else
		ins->instruction = RA;
	return (min(count_abs_min, count_abs_max));
}

// static void	after_rotate(t_ins *ins, int lstsize, int pos)
// {
	
// }

t_ins	best_rotate_pairs(t_node *lst, t_pairs pairs)
{
	int	lstsize;
	int	count_ins;
	t_ins	ins;

	if (pairs.gap < 0)
	{
		ins.error = 1;
		return (ins);
	}
	lstsize = ft_lstsize(lst);
	count_ins = min_count(lstsize, &ins, pairs);
	ins.times = count_ins;
	// after_rotate(&ins, lstsize, 1);
	return (ins);
}
