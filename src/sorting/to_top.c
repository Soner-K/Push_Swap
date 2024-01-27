/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:51:28 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 21:51:17 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Calculates the number of instructions needed to put
 * a given value, at a given position, to the top of the stack.
 * @param pos Position in the stack of the value to put on top.
 * @param lstsize Stack's size.
 * @param a Binary indicating if the stack is a (1) or not (0).
 * @returns Structure containing the type of instructions needed
 * and how may times to do it.
 */
t_cost	to_top(long pos, long lstsize, char a)
{
	t_cost	cost;

	if (pos > lstsize / 2)
	{
		cost.times_f = lstsize - pos;
		if (a == 1)
			cost.ins_f = RRA;
		else
			cost.ins_f = RRB;
	}
	else
	{
		cost.times_f = pos;
		if (a == 1)
			cost.ins_f = RA;
		else
			cost.ins_f = RB;
	}
	cost.ins_s = 0;
	cost.times_s = 0;
	cost.error = 0;
	return (cost);
}
