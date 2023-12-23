/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:24:54 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/23 15:43:20 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	d_node	*tmp;
	d_node	*first;
	d_node	*next;
	int		i;

	tmp = malloc(sizeof(d_node));
	tmp->data = -1;
	first = tmp;
	i = 0;
	tmp->prev = NULL;
	// add_node(&tmp, ft_lstnew(2));
	// add_node(&(tmp->next), ft_lstnew(3));
		//tmp->next sinon aucun lien entre node 2 et 3
	while (i < 11)
	{
		add_node(&tmp, ft_lstnew(i));
		tmp = tmp->next;
		i++;
	}
	tmp = first;
	next = first->next;
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	printf("\n");
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		if (!tmp->prev)
			break ;
		tmp = tmp->prev;
	}
	ra(&tmp);
	tmp = next;
	printf("\n");
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	tmp = next;
	rra(&tmp);
	printf("\n");
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	clear_list(&first);
}
