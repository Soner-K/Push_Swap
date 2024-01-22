/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:12:17 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/22 11:17:50 by sokaraku         ###   ########.fr       */
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
		return (sa(stack_a));
	if (!check(str, "sb"))
		return (sb(stack_b));
	if (!check(str, "ss"))
		return (ss(stack_a, stack_b));
	if (!check(str, "pa"))
		return (pa(stack_a, stack_b));
	if (!check(str, "pb"))
		return (pb(stack_b, stack_a));
	if (!check(str, "ra"))
		return (ra(stack_a));
	if (!check(str, "rb"))
		return (rb(stack_b));
	if (!check(str, "rrr"))
		return (rrr(stack_a, stack_b));
	if (!check(str, "rr") && (check(str, "rra") && check(str, "rrb")))
		return (rr(stack_a, stack_b));
	if (!check(str, "rra"))
		return (rra(stack_a));
	if (!check(str, "rrb"))
		return (rrb(stack_b));
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
	// t_ins	*ins;

	// t_pairs	pairs;
	// t_ins	ins;
	// t_ins	remaining;
	str[5] = '\0';
	str2 = NULL;
	stack_a = create_list(ac, av, 0);
	stack_b = NULL;
	last = 40;
	print_list(stack_a, NULL);
	print_tab(stack_a->sorted, ft_lstsize(stack_a));
	printf("\n");
	while (1)
	{
		if (stack_a)
		{
			// ins = best_rotate_min(stack_a, "next_min", last);
			// printf("Do %d %d times (nm) \n", ins.instruction, ins.times);
			// ins = best_rotate_min(stack_a, "min", last);
			// ins = find_value(stack_a, stack_a->sorted[find_index_min(stack_a,
			// 			stack_a->sorted, stack_a->sorted[last - 1])], 0);
			// printf("Do %d %d times (min) \n", ins.instruction, ins.times);
			// printf("Index of tab is %ld\n", find_index_min(stack_a,
			// 		stack_a->sorted, stack_a->sorted[last - 1]));
			// ins = test(stack_a, stack_a->sorted, 657);
			// 	printf("Instructions first min = %d et %ld fois\n",
			// 		ins[0].instruction,
			// 		ins[0].times);
			// 	printf("Instructions second min = %d et %ld fois\n",
			// 		ins[1].instruction,
			// 		ins[1].times);
			// pairs = find_pairs(stack_a, stack_a->sorted, last);
			// printf("pair f = %d pair s = %d. Gap = %ld\n", pairs.pos_first,
			// 	pairs.pos_second, pairs.gap);
			// if (pairs.gap >= 0)
			// 	ins = best_rotate_pairs(stack_a, pairs);
			// remaining = best_remaining(stack_a, 10, last);
			// printf("instruction = %d, times %d\n", ins.instruction,
			// ins.times);
			// printf("instruction_remain = %d, times %d\n",
			// remaining.instruction,
			// 	remaining.times);
		}
		read(1, str, 4);
		str2 = ft_fuse(str2, str);
		if (!check(str, "stop"))
			break ;
		execute(str, &stack_a, &stack_b);
		ft_bzero(str, 4);
		print_list(stack_a, stack_b);
	}
	print_tab(stack_a->sorted, ft_lstsize(stack_a));
	printf("\nCOMMANDES :\n%s\n", str2);
	count(str2);
	free(str2);
	clear_list(&stack_a, 1);
	clear_list(&stack_b, 0);
}

int	main(int ac, char **av)
{
	play(ac, av);
}