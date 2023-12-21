/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:24:54 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/21 12:28:22 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h" 

int	main(void)
{
	d_node *tmp;
	d_node *first;
	int		i;

	tmp = malloc(sizeof(d_node));
	tmp->data = -1;
	first = tmp;
	i = 0;

	tmp->prev = NULL;
	// add_node(&tmp, ft_lstnew(2));
	// add_node(&(tmp->next), ft_lstnew(3)); //tmp->next sinon aucun lien entre node 2 et 3
	while (i < 11)
	{
		add_node(&tmp, ft_lstnew(i));
		tmp = tmp->next;
		i++;
	}
	tmp = first;
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
	clear_list(&first);
}
