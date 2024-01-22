/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:42:30 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/22 15:32:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	to_top(t_node *lst, t_ins *ins)
{
	long	lstsize;
	long	pos;

	lstsize = ft_lstsize(lst);
	pos = find_pos(lst, ins[1].value);
	printf("\nPos = %ld\nins[0] = %d", pos, ins[0].instruction);
	if (ins[0].instruction == RRA)
		pos += ins[0].times;
	else
		pos -= ins[0].times;
	printf("\npos after = %ld\n", pos);
	if (pos > lstsize / 2)
	{
		ins[1].times += ins[0].times;
		ins[1].instruction = RRA;
	}
	else
	{
		ins[1].times -= ins[0].times;
		ins[1].instruction = RA;
	}
}

static void	ft_swap(t_ins *a, t_ins *b)
{
	t_ins	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	to_do_first(t_node *lst, t_ins *ins)
{
	if (ins[0].times > ins[1].times)
		ft_swap(&ins[0], &ins[1]);
	if (ins[0].instruction == RRA && ins[1].instruction == RRA)
		ins[1].times -= ins[0].times;
	else if (ins[0].instruction == RA && ins[1].instruction == RA)
		ins[1].times -= (ins[0].times + 1); // -1 car pb
	else
		to_top(lst, ins);
	printf("\nins 0 %d\nins 1 %d\n", ins[0].instruction, ins[1].instruction);
}

t_ins	*test(t_node *lst, int *sorted, int last)
{
	long	index;
	t_ins	*ins;

	ins = malloc(sizeof(t_ins) * 2);
	if (!ins)
		return (NULL);
	index = find_index_min(lst, sorted, lst->sorted[last - 1]);
	if (index < 0)
		return (NULL);
	ins[0] = find_value(lst, sorted[index], 0);
	if (sorted[index + 1])
		ins[1] = find_value(lst, sorted[index + 1], 0);
	else
		ins[1].error = 1;
	printf("\nins 0 %d\nins 1 %d\n", ins[0].instruction, ins[1].instruction);
	to_do_first(lst, ins);
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