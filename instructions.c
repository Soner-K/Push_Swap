/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:54 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/21 12:58:51 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sa(d_node **first_a, d_node **second_a)
// {
// 	int	tmp;

// 	if (!(*first_a) || !(*second_a))
// 		return ;
// 	tmp = (*first_a)->data;
// 	(*first_a)->data = (*second_a)->data;
// 	(*second_a)->data = tmp;
// }

// void	sb(d_node **first_b, d_node **second_b)
// {
// 	int	tmp;

// 	if (!(*first_b) || !(*second_b))
// 		return ;
// 	tmp = (*first_b)->data;
// 	(*first_b)->data = (*second_b)->data;
// 	(*second_b)->data = tmp;
// }

// void	ss(d_node **f_a, d_node **s_a, d_node **f_b, d_node **s_b)
// {
// 	sa(f_a, s_a);
// 	sb(f_b, s_b);
// }

void	sa(d_node **first_a)
{
	int	tmp;

	if (!(*first_a) || !(*first_a)->next)
		return ;
	tmp = (*first_a)->data;
	(*first_a)->data = (*first_a)->next->data;
	(*first_a)->next->data = tmp;
}

void	sb(d_node **first_b)
{
	int	tmp;

	if (!(*first_b) || !(*first_b)->next)
		return ;
	tmp = (*first_b)->data;
	(*first_b)->data = (*first_b)->next->data;
	(*first_b)->next->data = tmp;
}

void	ss(d_node **f_a, d_node **f_b)
{
	sa(f_a);
	sb(f_b);
}

int	main(void)
{
	d_node *tst;

	tst = ft_lstnew(0);
	tst->next = ft_lstnew(1);

	printf("%d\n%d\n\n\n", tst->data, tst->next->data);
	sa(&tst);
	printf("%d\n%d\n\n\n", tst->data, tst->next->data);
	sa(&tst);
	printf("%d\n%d", tst->data, tst->next->data);
}