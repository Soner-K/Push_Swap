/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:12:17 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/23 16:15:55 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check(const char *s1, const char *s2)
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

static void	execute(char *str, t_node **stack_a, t_node **stack_b)
{
	if (!check(str, "sa"))
		return (sa(stack_a, NULL));
	if (!check(str, "sb"))
		return (sb(stack_b, NULL));
	if (!check(str, "ss"))
		return (ss(stack_a, stack_b, NULL));
	if (!check(str, "pa"))
		return (pa(stack_a, stack_b, NULL));
	if (!check(str, "pb"))
		return (pb(stack_b, stack_a, NULL));
	if (!check(str, "ra"))
		return (ra(stack_a, NULL));
	if (!check(str, "rb"))
		return (rb(stack_b, NULL));
	if (!check(str, "rrr"))
		return (rrr(stack_a, stack_b, NULL));
	if (!check(str, "rr") && (check(str, "rra") && check(str, "rrb")))
		return (rr(stack_a, stack_b, NULL));
	if (!check(str, "rra"))
		return (rra(stack_a, NULL));
	if (!check(str, "rrb"))
		return (rrb(stack_b, NULL));
	write(1, "Error\n", 6);
}

static void	count(char *str)
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

static void	print_tab(int *tab, int last)
{
	while (last--)
		printf("|%d| ", *tab++);
}

void	play(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	str[6];
	char	*str2;
	int		last;
	int		i;
	t_ins	*ins;

	i = 0;
	str2 = NULL;
	stack_a = create_list(ac, av, 0);
	stack_b = NULL;
	last = 9;
	print_list(stack_a, NULL);
	print_tab(stack_a->sorted, ft_lstsize(stack_a));
	printf("\n");
	while (1)
	{
		if (stack_a && i != 1)
		{
			ins = best_pairs(stack_a, stack_a->sorted, stack_a->sorted[last
					- 1], last);
			i = 1;
			printf("Do ins 1 = %d et times %ld\n", ins[0].instruction,
				ins[0].times);
			printf("Do ins 2 = %d et times %ld\n", ins[1].instruction,
				ins[1].times);
		}
		read(1, str, 4);
		str2 = ft_fuse(str2, str);
		if (!check(str, "stop"))
			break ;
		execute(str, &stack_a, &stack_b);
		ft_bzero(str, 4);
		print_list(stack_a, stack_b);
		// if (find())
	}
	print_tab(stack_a->sorted, ft_lstsize(stack_a));
	printf("\nCOMMANDES :\n%s\n", str2);
	count(str2);
	free(str2);
	clear_list(&stack_a, 1);
	clear_list(&stack_b, 0);
}

// int	main(int ac, char **av)
// {
// 	play(ac, av);
// }