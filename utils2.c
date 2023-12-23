/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:26:39 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/23 20:31:33 by sokaraku         ###   ########.fr       */
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

void	print_list(d_node *first_a, d_node *first_b) // à enlever pour la correction
{
	if (!first_a && !first_b)
		return ;
	while (first_a || first_b)
	{
		printf("%d\n", first_a->data);
		first_a = first_a->next;
		first_b = first_b->next;
	}
}