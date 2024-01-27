/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:27:26 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 21:36:20 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_sizes		sizes;
	char		str[1000];

	str[999] = 0;
	stack_a = create_list(ac, av, 0);
	if (!stack_a)
		return (1);
	if (is_sorted(stack_a) || ac == 2)
		return (clear_list(&stack_a), 1);
	stack_b = NULL;
	sizes.lstsize_a = ft_lstsize(stack_a);
	sizes.lstsize_b = 0;
	sort(&stack_a, &stack_b, &sizes);
	read(0, str, 1000);
	printf("commandes %s\n", str);
	clear_list(&stack_a);
	clear_list(&stack_b);
}