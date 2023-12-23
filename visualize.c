/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:12:17 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/23 20:30:24 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;

	i = 0;
	s1_cp = (unsigned char *)s1;
	s2_cp = (unsigned char *)s2;
	while ((s1[i] || s2[i]))
	{
		if (s1_cp[i] != s2_cp[i])
			return (s1_cp[i] - s2_cp[i]);
		i++;
	}
	return (0);
}

void	execute(char *str, d_node *stack_a, d_node *stack_b)
{
	if (!ft_strcmp(str, "sa"))
		sa(&stack_a);
	if (!ft_strcmp(str, "sb"))
		sb(&stack_b);
	if (!ft_strcmp(str, "ss"))
		ss(&stack_a, &stack_b);
	if (!ft_strcmp(str, "pa"))
		pa(&stack_a, &stack_b);
	if (!ft_strcmp(str, "pb"))
		pb(&stack_b, &stack_a);
	if (!ft_strcmp(str, "ra"))
		ra(&stack_a);
	if (!ft_strcmp(str, "rb"))
		rb(&stack_b);
	if (!ft_strcmp(str, "rr"))
		rr(&stack_a, &stack_b);
	if (!ft_strcmp(str, "rra"))
		rra(&stack_a);
	if (!ft_strcmp(str, "rrb"))
		rrb(&stack_b);
	if (!ft_strcmp(str, "rrr"))
		rrr(&stack_a, &stack_b);
}

int	main(int ac, char **av)
{
	d_node *stack_a;
	d_node *stack_b;
	char str[5];

	str[4] = '\0';
	stack_a = create_list(ac, av);
	stack_b = malloc(sizeof(d_node));
	// if (!stack_a || stack_b)
	// 	return (0);
	while (1)
	{
		read(1, str, 4);
		if (!ft_strcmp(str, "stop"))
			break ;
		execute(str, stack_a, stack_b);
		print_list(stack_a, stack_b);
	}
	clear_list(&stack_a);
	clear_list(&stack_b);
}