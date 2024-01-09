/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:54 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/09 17:15:07 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Does sa and sb at the same time (I'm using sa two times since I use it
anyway in rb so there's no need to call a function that will 
call another one when I can call it directly).*/
void	ss(d_node **first_a, d_node **first_b)
{
	sa(first_a);
	sa(first_b);
}

/* ra and rb.*/
void	rr(d_node **first_a, d_node **first_b)
{
	if (!(*first_a) || !(*first_b))
		return ;
	ra(first_a);
	ra(first_b);
}

/*rra and rrb.*/
void	rrr(d_node **first_a, d_node **first_b)
{
	rra(first_a);
	rra(first_b);
}

// int	main(void)
// {
// 	d_node *tst;
// 	d_node *tst2;
// 	d_node *first;

// 	tst = ft_lstnew(0);
// 	tst->next = ft_lstnew(1);
// 	first = tst;
// 	tst2 = ft_lstnew(1450);

// 	printf("TST DATA\n%d\n", tst->data);
// 	pa(&tst, &tst2);
// 	printf("TST DATA\n%d\n", tst->data);
// 	pb(&tst2, &tst);
// 	printf("TST2 DATA\n%d\n", tst2->data);
// 	printf("TST DATA\n%d\n", tst->data);
// 	printf("last node %d\n", (ft_lstlast(first))->data);
// 	printf("node first %d\n", first->data);
// }