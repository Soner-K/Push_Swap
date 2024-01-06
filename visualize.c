/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:12:17 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/06 16:39:55 by sokaraku         ###   ########.fr       */
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
	while ((s1[i] && s2[i]))
	{
		if (s1_cp[i] != s2_cp[i])
			return (s1_cp[i] - s2_cp[i]);
		i++;
	}
	return (0);
}

void	execute(char *str, d_node **stack_a, d_node **stack_b)
{
	if (!ft_strcmp(str, "sa"))
		return (sa(stack_a));
	if (!ft_strcmp(str, "sb"))
		return (sb(stack_b));
	if (!ft_strcmp(str, "ss"))
		return (ss(stack_a, stack_b));
	if (!ft_strcmp(str, "pa"))
		return (pa(stack_a, stack_b));
	if (!ft_strcmp(str, "pb"))
		return (pb(stack_b, stack_a));
	if (!ft_strcmp(str, "ra"))
		return (ra(stack_a));
	if (!ft_strcmp(str, "rb"))
		return (rb(stack_b));
	if (!ft_strcmp(str, "rrr"))
		return (rrr(stack_a, stack_b));
	if (!ft_strcmp(str, "rr") && (ft_strcmp(str, "rra") && ft_strcmp(str,
				"rrb")))
		return (rr(stack_a, stack_b));
	if (!ft_strcmp(str, "rra"))
		return (rra(stack_a));
	if (!ft_strcmp(str, "rrb"))
		return (rrb(stack_b));
	write(1, "Error\n", 6);
}

void	count(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if ((*str) == '\n')
			count++;
		str++;
	}
	printf("Nombre d'instructions : %d\n", count);
}

int	main(int ac, char **av)
{
	d_node	*stack_a;
	d_node	*stack_b;
	char	str[6];
	char	*str2;

	str[5] = '\0';
	str2 = NULL;
	stack_a = create_list(ac, av);
	stack_b = malloc(sizeof(d_node));
	stack_b = NULL;
	print_list(stack_a, NULL);
	while (1)
	{
		read(1, str, 4);/**/
		str2 = ft_fuse(str2, str);
		if (!ft_strcmp(str, "stop"))
			break ;
		execute(str, &stack_a, &stack_b);
		print_list(stack_a, stack_b);
	}
	printf("COMMANDES :\n%s\n", str2);
	count(str2);
	free(str2);
	clear_list(&stack_a);
	clear_list(&stack_b);
}