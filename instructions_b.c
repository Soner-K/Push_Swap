/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:40:09 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/23 15:41:39 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the first two elements at the top of the stack B.*/
void	sb(d_node **first_b)
{
	sa(first_b);
}

/*Pushes the top element of A's stack (push) to the top of B's stack (store).*/
void	pb(d_node **store, d_node **push)
{
	pa(store, push);
}

/*Shift up all the nodes of stack B once. It can be done by simply placing
the first node to the last position of the stack.*/
void	rb(d_node **first_node)
{
	if (!(*first_node))
		return ;
	ra(first_node);
}

/*Shift down all the nodes of stack B once. */
void	rrb(d_node **first_node)
{
	rra(first_node);
}