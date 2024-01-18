/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_remaining.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:51:52 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/18 14:18:23 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// t_ins	best_remaining(t_node *lst, int lstsize, int last)
// {
// 	t_ins	ins;
// 	int		index;

// 	index = find_index_min(lst, lst->sorted, lst->sorted[last - 1]);
// 	if (index < 0)
// 	{
// 		ins.error = 1;
// 		return (ins);
// 	}
// 	if (index > lstsize / 2)
// 	{
// 		ins.instruction_ = RRA;
// 		ins.times = lstsize - index;
// 	}
// 	else
// 	{
// 		ins.instruction = RA;
// 		ins.times = index;
// 	}
// 	ins.error = 0;
// 	return (ins);
// }