/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:26:39 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/25 17:33:05 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(d_node **lst, d_node *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->prev = ft_lstlast(*lst);
	ft_lstlast(*lst)->next = new;
}

void	print_list(d_node *first_a, d_node *first_b)
{
	printf("Stack A\t\tStack B\n");
	while (first_a != NULL || first_b != NULL)
	{
		if (first_a != NULL)
		{
			printf("%d\t\t", first_a->data);
			first_a = first_a->next;
		}
		// else
		// {
		// 	printf("\t");
		// }
		if (first_b != NULL)
		{
			printf("%d", first_b->data);
			first_b = first_b->next;
		}
		printf("\n");
	}
}