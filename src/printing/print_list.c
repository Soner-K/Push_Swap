/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:37 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/26 15:13:25 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_list(t_node *first_a, t_node *first_b)
{
	printf("Stack A\t\t\t\tStack B\n");
	while (first_a != NULL || first_b != NULL)
	{
		if (first_a != NULL)
		{
			printf("%ld", first_a->data);
			first_a = first_a->next;
		}
		printf("\t\t\t\t");
		if (first_b != NULL)
		{
			printf("%ld", first_b->data);
			first_b = first_b->next;
		}
		printf("\n");
	}
}
