/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:40:09 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/23 16:14:51 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Swaps the first two elements at the top of the stack B.*/
void	sb(t_node **first_b, char *s)
{
	sa(first_b, NULL);
	ft_putstr(s);
}

/*Pushes the top element of A's stack (push) to the top of B's stack (store).*/
void	pb(t_node **store, t_node **push, char *s)
{
	pa(store, push, NULL);
	ft_putstr(s);
}

/*Shift up all the nodes of stack B once. It can be done by simply placing
the first node to the last position of the stack.*/
void	rb(t_node **first_node, char *s)
{
	if (!(*first_node))
		return ;
	ra(first_node, NULL);
	ft_putstr(s);
}

/*Shift down all the nodes of stack B once. */
void	rrb(t_node **first_node, char *s)
{
	rra(first_node, NULL);
	ft_putstr(s);
}
