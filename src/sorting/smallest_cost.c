/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:58:02 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/25 18:59:53 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static long	to_top(t_node *lst, long pos, char pushed)
{
	static long	lstsize;
	long		cost_to_top;

	if (pushed == 1)
		// return apres ? ou gerer ca dans les fonctions appelantes ?
		lstsize--;
	lstsize = ft_lstsize(lst);
	if (pos > lstsize / 2)
		cost_to_top = lstsize - pos;
	else
		cost_to_top = pos;
	return (cost_to_top);
}

long	find_closest_pos(int value, t_node *stack_b)
{
	long	diff;
	t_node	*first;
	long	pos;
	long	closest;

	diff = INT_MAX;
	closest = 2147483649;
	printf("%ld\n", closest);
	pos = 0;
	first = stack_b;
	while (stack_b)
	{
		if (value > stack_b->data && value - stack_b->data < diff)
		{
			closest = stack_b->data;
			diff = value - stack_b->data;
		}
		stack_b = stack_b->next;
	}
	stack_b = first;
	pos = find_pos_in_stack(stack_b, closest);
	return (pos);
}

long	find_cost(t_node *stack_a, t_node *stack_b) // penser a protection
{
	int cost_a;
	int cost_b;

	cost_a = 0;
	cost_b = 0;
	cost_a = to_top(stack_a, find_pos_in_stack(stack_a, stack_a->data), 0);
	cost_b = to_top(stack_b, find_pos_in_stack(stack_b, stack_b->data), 0);
	return (cost_a + cost_b);
}

// int	find_smallest_cost(t_node *stack_a, t_node *stack_b)
// {
// }