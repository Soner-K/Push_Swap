/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjusted_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:47:03 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 14:50:49 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Calculates the best instructions if a and b both
 * contain the rotate instruction.
 * @param a The instruction to do in stack A, and how many times.
 * @param b The instruction to do in stack B, and how many times.
 * @returns The final instruction set.
 */
t_cost	new_rotate(t_cost a, t_cost b)
{
	t_cost	final;

	final.ins_f = RR;
	final.times_f = ft_min(a.times_f, b.times_f);
	if (a.times_f > b.times_f)
	{
		final.ins_s = RA;
		final.times_s = a.times_f - b.times_f;
	}
	else if (a.times_f < b.times_f)
	{
		final.ins_s = RB;
		final.times_s = b.times_f - a.times_f;
	}
	else
	{
		final.ins_s = 0;
		final.times_s = 0;
	}
	final.error = 0;
	return (final);
}

/**
 * @brief Calculates the best instructions if a and b both
 * contain the reverse rotate instruction.
 * @param a The instruction to do in stack A, and how many times.
 * @param b The instruction to do in stack B, and how many times.
 * @returns The final instruction set.
 */
t_cost	new_reverse_rotate(t_cost a, t_cost b)
{
	t_cost	final;

	final.ins_f = RRR;
	final.times_f = ft_min(a.times_f, b.times_f);
	if (a.times_f > b.times_f)
	{
		final.ins_s = RRA;
		final.times_s = a.times_f - b.times_f;
	}
	else if (a.times_f < b.times_f)
	{
		final.ins_s = RRB;
		final.times_s = b.times_f - a.times_f;
	}
	else
	{
		final.ins_s = 0;
		final.times_s = 0;
	}
	final.error = 0;
	return (final);
}
