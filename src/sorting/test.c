/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:42:30 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/22 11:17:55 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static void	print_tab(int *tab, int last)
// {
// 	while (*tab != last)
// 		printf("|%d| ", *tab++);
// }

static void	ft_swap(t_ins *a, t_ins *b)
{
	t_ins	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	to_do_first(t_ins *ins)
{
	if (ins[0].times > ins[1].times)
		ft_swap(&ins[0], &ins[1]);
	// if (ins[0].instruction == RRA)
	// 	ins[1].times = 
}

t_ins	*test(t_node *lst, int *sorted, int last)
{
	long	i;
	long	index;
	t_ins	*ins;
	size_t	lstsize;

	i = 0;
	lstsize = ft_lstsize(lst);
	ins = malloc(sizeof(t_ins) * 2);
	if (!ins)
		return (NULL);
	index = find_index_min(lst, sorted, last);
	printf("index = %ld\n", index);
	if (index < 0)
		return (NULL);
	ins[0] = find_value(lst, sorted[index], 0);
	if (sorted[index + 1])
		ins[1] = find_value(lst, sorted[index + 1], 0);
	else
		ins[1].error = 1;
	to_do_first(ins);
	return (ins);
}

// int	main(int ac, char **av)
// {
// 	t_node *lst;
// 	lst = create_list(ac, av, 0);
// 	t_ins *ins;

// 	ins = test(lst, lst->sorted, 457);
// 	print_list(lst, NULL);
// 	printf("Instructions first min = %d et %ld fois\n", ins[0].instruction,
// 		ins[0].times);
// 	printf("Instructions second min = %d et %ld fois\n", ins[1].instruction,
// 		ins[1].times);
// 	clear_list(&lst, 1);
// 	free(ins);
// }