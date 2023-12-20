/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:24:54 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/20 18:51:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_node(t_list **node, t_list *insert)
{
	if (!(*node) || !insert)
		return ;
	insert->next = (*node)->next;
	(*node)->next = insert;
	insert->prev = (*node);
}

int	main(void)
{
	t_list *tmp;
	t_list *first;

	tmp = malloc(sizeof(t_list));
	tmp->data = 1;
	first = tmp;

	tmp->prev = NULL;
	add_node(&tmp, ft_lstnew(2));
	add_node(&tmp, ft_lstnew(3));
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	printf("\n");
	printf("%d", tmp->data);
	printf("\n");
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		if (!tmp->prev)
			break ;
		tmp = tmp->prev;
	}
	printf("%d", tmp->data);
}
