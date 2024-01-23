/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:41:20 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/23 18:41:29 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_config(t_node **a, t_node **b, char *swap_a, char *swap_b)
{
	int	next_data_a;
	int	next_data_b;

	if (!(*a)->next || !(*b)->next)
		return ;
	next_data_a = (*a)->next->data;
	next_data_b = (*b)->next->data;
	if ((*a)->data > next_data_a) // si next = null?
		*swap_a = 1;
	if ((*b)->data < next_data_b) // si next = null?
		*swap_b = 1;
}

void	exec_swap(t_node **stack_a, t_node **stack_b)
{
	char	swap_a;
	char	swap_b;

	swap_a = 0;
	swap_b = 0;
	set_config(stack_a, stack_b, &swap_a, &swap_b);
	if (swap_a + swap_b == 2)
		ss(stack_a, stack_b, "ss\n");
	else if (swap_b == 1)
		sb(stack_b, "sb\n");
	else if (swap_a == 1)
		sa(stack_a, "sa\n");
}

void	exec_push(t_node **stack_a, t_node **stack_b, char push_b)
{
	if (push_b == 1)
		pb(stack_b, stack_a, "pb\n");
	else
		pa(stack_a, stack_b, "pa\n");
}

void	exec_rotate(t_node **stack_a, t_node **stack_b, t_ins *ins)
{
	// if (!ins)
	// 	return ;
	if (ins[0].instruction == RRA)
	{
		while (ins[0].times--)
			rra(stack_a, "rra\n");
	}
	else if (ins[0].instruction == RA)
	{
		while (ins[0].times--)
			ra(stack_a, "ra\n");
	}
	// if (stack_a && stack_b)
	// {
	exec_push(stack_a, stack_b, 1);
	// }
	if (ins[1].instruction == RRA && ins[1].error != 1)
	{
		while (ins[1].times--)
			rra(stack_a, "rra\n");
	}
	else if (ins[1].instruction == RA && ins[1].error != 1)
	{
		while (ins[1].times--)
			ra(stack_a, "ra\n");
	}
	if (ins[1].error != 1)
		if (stack_a && stack_b)
			exec_push(stack_a, stack_b, 1);
	if (stack_a && stack_b)
		exec_swap(stack_a, stack_b);
	free(ins);
}

int	main(int ac, char **av)
{
	t_node	*lst;
	t_node	*lst2;
	t_ins	*ins;
	long	lstsize;

	lst = create_list(ac, av, 0);
	if (!lst)
		return (-1);
	lst2 = NULL;
	lstsize = ft_lstsize(lst);
	// print_list(lst, lst2);
	// printf("\n\n\n");
	while (lstsize > 4)
	{
		ins = best_pairs(lst, lst->sorted, lst->sorted[ac - 2], ac - 2);
		exec_rotate(&lst, &lst2, ins);
		lstsize -= 2;
	}
	printf("\n\n\n");
	print_list(lst, lst2);
}
