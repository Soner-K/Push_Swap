/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:07:37 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/28 19:07:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// int	main(int ac, char **av)
// {
// 	t_node *stack_a;
// 	t_node *stack_b;
// 	char *str;
//
// 	stack_a = create_list(ac, av, 0);
// 	if (!stack_a || ac == 1)
// 		ft_quit();
// 	stack_b = NULL;
// 	str = get_next_line(0, 0);
// 	while (str[0] != '\n')
// 	{
// 		execute(str, &stack_a, &stack_b);
// 		free(str);
// 		str = get_next_line(0, 0);
// 	}
// 	if (is_sorted(stack_a))
// 		ft_putstr("OK\n", 1);
// 	else
// 		ft_putstr("KO\n", 1);
// 	free_and_out(&stack_a, &stack_b, 0);
// 	return (0);
// }