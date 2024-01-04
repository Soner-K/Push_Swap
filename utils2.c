/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:26:39 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/04 16:37:15 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_fuse(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j])
			new[i++] = s2[j++];
	new[i] = 0;
	free(s1);
	return (new);
}

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
			printf("%d", first_a->data);
			first_a = first_a->next;
		}
		printf("\t\t");
		if (first_b != NULL)
		{
			printf("%d", first_b->data);
			first_b = first_b->next;
		}
		printf("\n");
	}
}