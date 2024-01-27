/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:12:17 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 14:05:28 by sokaraku         ###   ########.fr       */
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
		return (do_it_one(stack_a, sa));
	if (!check(str, "sb"))
		return (do_it_one(stack_b, sb));
	if (!check(str, "ss"))
		return (do_it_two(stack_a, stack_b, ss, 1));
	if (!check(str, "pa"))
		return (do_it_two(stack_a, stack_b, pa, 1));
	if (!check(str, "pb"))
		return (do_it_two(stack_b, stack_a, pb, 1));
	if (!check(str, "ra"))
		return (do_it_one(stack_a, ra));
	if (!check(str, "rb"))
		return (do_it_one(stack_b, rb));
	if (!check(str, "rrr"))
		return (do_it_two(stack_a, stack_b, rrr, 1));
	if (!check(str, "rr") && (check(str, "rra") && check(str, "rrb")))
		return (do_it_two(stack_a, stack_b, rr, 1));
	if (!check(str, "rra"))
		return (do_it_one(stack_a, rra));
	if (!check(str, "rrb"))
		return (do_it_one(stack_b, rrb));
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
	t_cost	smol;
	t_cost	last;
	long	big;
	t_sizes	sizes;
	char	str[6];
	char	*str2;

	str2 = NULL;
	stack_a = create_list(ac, av, 0);
	stack_b = NULL;
	print_list(stack_a, NULL);
	print_tab(stack_a->sorted, ft_lstsize(stack_a));
	printf("\n");
	while (1)
	{
		read(1, str, 4);
		str2 = ft_fuse(str2, str);
		if (!check(str, "stop"))
			break ;
		execute(str, &stack_a, &stack_b);
		sizes.lstsize_a = ft_lstsize(stack_a);
		sizes.lstsize_b = ft_lstsize(stack_b);
		ft_bzero(str, 4);
		print_list(stack_a, stack_b);
		if (sizes.lstsize_a > 3)
		{
			smol = smallest_cost_to_b(stack_a, stack_b, sizes);
			printf("Do instruction %d %d times\n", smol.ins_f, smol.times_f);
			printf("Do instruction %d %d times\n", smol.ins_s, smol.times_s);
			printf("closest pos %ld\n", closest_smallest_in_b(stack_a->data,
					stack_b));
		}
		else
		{
			while (!check(str, "stop") && ft_lstsize(stack_b) != 0)
			{
				big = closest_biggest_in_a(stack_b->data, stack_a);
				last = smallest_cost_to_a(stack_a, sizes, stack_b->data);
				printf("pos of closest biggest for %ld is %ld\n", stack_b->data,
					big);
				printf("Do instruction %d %d times\n", last.ins_f,
					last.times_f);
				read(1, str, 4);
				execute(str, &stack_a, &stack_b);
				sizes.lstsize_a = ft_lstsize(stack_a);
				str2 = ft_fuse(str2, str);
				print_list(stack_a, stack_b);
				ft_bzero(str, 4);
			}
		}
	}
	print_tab(stack_a->sorted, ft_lstsize(stack_a));
	printf("\nCOMMANDES :\n%s\n", str2);
	count(str2);
	free(str2);
	clear_list(&stack_a, 1);
	clear_list(&stack_b, 0);
}

// void	play(int ac, char **av)
// {
// 	t_node *stack_a;
// 	t_node *stack_b;
// 	t_cost smol;
// 	t_sizes	sizes;
// 	char str[6];
// 	char *str2;

// 	str2 = NULL;
// 	stack_a = create_list(ac, av, 0);
// 	stack_b = NULL;
// 	print_list(stack_a, NULL);
// 	print_tab(stack_a->sorted, ft_lstsize(stack_a));
// 	printf("\n");
// 	while (1)
// 	{
// 		sizes.lstsize_a = ft_lstsize(stack_a);
// 		sizes.lstsize_b = ft_lstsize(stack_b);
// 		read(1, str, 4);
// 		str2 = ft_fuse(str2, str);
// 		if (!check(str, "stop"))
// 			break ;
// 		execute(str, &stack_a, &stack_b);
// 		ft_bzero(str, 4);
// 		print_list(stack_a, stack_b);
// 		smol = smallest_cost_to_b(stack_a, stack_b, sizes);
// 		printf("Do instruction %d %d times\n", smol.ins_f, smol.times_f);
// 		printf("Do instruction %d %d times\n", smol.ins_s, smol.times_s);
// 		printf("closest pos %ld\n", closest_smallest_in_b(stack_a->data,
// stack_b));
// 	}
// 	print_tab(stack_a->sorted, ft_lstsize(stack_a));
// 	printf("\nCOMMANDES :\n%s\n", str2);
// 	count(str2);
// 	free(str2);
// 	clear_list(&stack_a, 1);
// 	clear_list(&stack_b, 0);
// }

int	main(int ac, char **av)
{
	play(ac, av);
}
