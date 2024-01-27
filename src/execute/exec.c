/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:01:03 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 19:26:58 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Does the first part of the instructions.
 * @param a Pointer to stack A's first node.
 * @param b Pointer to stack B's first node.
 * @param set The set of instructions to do.
 * @return void.
 */
void	do_it_first(t_node **a, t_node **b, t_cost set)
{
	if (set.error == 1)
		return ;
	if (set.ins_f == RA)
		while (set.times_f--)
			ra(a);
	if (set.ins_f == RB)
		while (set.times_f--)
			rb(b);
	if (set.ins_f == RR)
		while (set.times_f--)
			rr(a, b);
	if (set.ins_f == RRA)
		while (set.times_f--)
			rra(a);
	if (set.ins_f == RRB)
		while (set.times_f--)
			rrb(b);
	if (set.ins_f == RRR)
		while (set.times_f--)
			rrr(a, b);
}

/**
 * @brief Does the second part of the instructions.
 * @param a Pointer to stack A's first node.
 * @param b Pointer to stack B's first node.
 * @param set The set of instructions to do.
 * @return void.
 */
void	do_it_second(t_node **a, t_node **b, t_cost set)
{
	if (set.error == 1)
		return ;
	if (set.ins_s == RA)
		while (set.times_s--)
			ra(a);
	if (set.ins_s == RB)
		while (set.times_s--)
			rb(b);
	if (set.ins_s == RR)
		while (set.times_s--)
			rr(a, b);
	if (set.ins_s == RRA)
		while (set.times_s--)
			rra(a);
	if (set.ins_s == RRB)
		while (set.times_s--)
			rrb(b);
	if (set.ins_s == RRR)
		while (set.times_s--)
			rrr(a, b);
}
