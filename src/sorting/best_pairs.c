/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_pairs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:42:30 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/23 18:39:08 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Modify the second instruction to do (ins[1]), considering
the impacts of the first instruction (ins[0]) in the stack A.
This function is called only in the cases where the instructions 
of ins[0] and ins[1] aren't the same (RRA and RA).*/
static void	to_top(t_node *lst, t_ins *ins) //attention quand lst diminue en taille?
{
	long	lstsize;
	long	pos;

	lstsize = ft_lstsize(lst);
	pos = find_pos_in_stack(lst, ins[1].value);
	if (ins[0].instruction == RRA)
		pos += ins[0].times;
	else
		pos -= ins[0].times;
	if (pos > lstsize / 2)
	{
		ins[1].times = lstsize - pos;
		ins[1].instruction = RRA;
	}
	else
	{
		ins[1].times = pos - 1;
		ins[1].instruction = RA;
	}
}

/*Swapping is done if and only if the first instruction 
to do has the biggest count.*/
static void	ft_swap(t_ins *a, t_ins *b)
{
	t_ins	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*Checks the instruction inside the ins array and swaps,
modify the count, or the instructions, accordingly.*/
static void	to_do_first(t_node *lst, t_ins *ins)
{
	if (ins[0].times > ins[1].times)
		ft_swap(&ins[0], &ins[1]);
	if (ins[0].instruction == RRA && ins[1].instruction == RRA)
		ins[1].times -= ins[0].times;
	else if (ins[0].instruction == RA && ins[1].instruction == RA)
	{
		if (ins[1].times == 0)
			ins[0].times -= 2;
		else
			ins[1].times -= ins[0].times + 1;
	}
	else
		to_top(lst, ins);
}

/*Retrieve the actual's two minimum in stack A, and calculate
the shortest way to push them into stack B, using rotate instructions
(RRA and/or RA).*/
t_ins	*best_pairs(t_node *lst, int *sorted, int last, long size)
{
	long	index;
	t_ins	*ins;
	ins = malloc(sizeof(t_ins) * 2);
	if (!ins)
		return (NULL);
	index = find_index_min(lst, sorted, last);
	ins[1].error = 0;
	if (index < 0 || index >= size)
		return (NULL);
	ins[0] = best_rotate(lst, sorted[index]);
	if (index + 1 < size)
		ins[1] = best_rotate(lst, sorted[index + 1]);
	else
		ins[1].error = 1;
	to_do_first(lst, ins);
	if (ins[0].times == 0)
		ins[0].instruction = PB;
	if (ins[1].times == 0)
		ins[1].instruction = PB;
	return (ins);
}
