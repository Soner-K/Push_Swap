/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:07:37 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 15:38:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*str;

	if (ac == 1)
		exit(1);
	stack_a = create_list(ac, av, 0);
	if (!stack_a)
		ft_quit();
	stack_b = NULL;
	str = get_next_line(0, 0);
	while (str)
	{
		execute(str, &stack_a, &stack_b);
		free(str);
		str = get_next_line(0, 0);
	}
	if (str)
		free(str);
	if (is_sorted(stack_a))
		ft_putstr("OK\n", 1);
	else
		ft_putstr("KO\n", 1);
	free_and_out(&stack_a, &stack_b, 0);
	return (0);
}
