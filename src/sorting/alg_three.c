/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/25 15:41:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	find_max_in_stack_a(t_node *stack_a)
{
	int		first;

	first = stack_a->data;
	stack_a = stack_a->next;
	if (first > stack_a->data && first > stack_a->next->data)
		return (0);
	if (stack_a->data > first && stack_a->data > stack_a->next->data)
		return (1);
	else
		return (2);
}

void	sort_for_three(t_node **stack_a)
{
	char	pos_max;

	pos_max = find_max_in_stack_a(*stack_a);
	if (pos_max == 0)
		ra(stack_a);
	else if (pos_max == 1)
		rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

// int	main(int ac, char **av)
// {
// 	t_node *lst;

// 	lst = create_list(ac, av, 0);
// 	if (!lst)
// 		return (1);
// 	print_list(lst, NULL);
// 	sort_for_three(&lst);
// 	print_list(lst, NULL);
// 	clear_list(&lst, 0);
// }