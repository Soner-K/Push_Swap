/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotate_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:01:20 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/18 17:22:54 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*GERER LES PA ET PB ET LEUR IMPACT SUR SORTED*/

static void	check_mode(t_node *lst, char *mode, t_min *min, int size)
{
	if (!mode)
		return ;
	if (!ft_strcmp("next_min", mode))
	{
		*min = find_next_min(lst);	
	}
	else
		*min = find_min(lst, lst->sorted, size);
}

/*find the best instruction to attain the min value*/

t_ins	best_rotate_min(t_node *lst, char *mode, int size) // proteger pour !lst?
{
	t_ins	ins;
	size_t	lstsize;
	int		count;
	t_min	min;

	lstsize = ft_lstsize(lst);
	count = 0;
	check_mode(lst, mode, &min, size);
	if (min.gap > lstsize / 2)
	{
		ins.instruction = RRA;
		count = lstsize;
	}
	else
		ins.instruction = RA;
	while (lst && lst->data != min.value)
	{
		if (ins.instruction == RRA)
			count--;
		else
			count++;
		lst = lst->next;
	}
	ins.times = count;
	return (ins); ///////////////// ATTENTION AUX LEAKS \\\\\\\\\\\\\\\\\\\/
}

// int main(int ac, char **av)
// {
// 	play(ac, av);
// }