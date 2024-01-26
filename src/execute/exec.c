/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:01:03 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/26 15:14:57 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Does swap (a or b) one time.
 * @param stack Address to the first node of a stack.
 * @param swap Function pointer to instructions that need only one stack
 * (ra, rb, rra, rrb, sa, sb).
 * @return void.
 */
void	do_it_one(t_node **stack, t_exec_swap swap_one)
{
	swap_one(stack);
}

/**
 * @brief Does the instruction passed as a function as long as times is not 0.
 * @param a Address to the first node of stack a.
 * @param b Address to the first node of stack b.
 * @param ins Function pointer to instructions that need two stacks
 * (rr, rrr, ss, pa and pb).
 * @param times Number of times to execute the instruction.
 * @return void.
 */
void	do_it_two(t_node **a, t_node **b, t_exec ins, long times)
{
	while (times--)
		ins(a, b);
}
