/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:54 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/21 15:31:19 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the first two elements at the top of the stack A*/
void	sa(d_node **first_a)
{
	int	tmp;

	if (!(*first_a) || !(*first_a)->next)
		return ;
	tmp = (*first_a)->data;
	(*first_a)->data = (*first_a)->next->data;
	(*first_a)->next->data = tmp;
}

/* Swaps the first two elements at the top of the stack B*/
void	sb(d_node **first_b)
{
	sa(first_b);
}

/*Does sa and sb at the same time*/
void	ss(d_node **first_a, d_node **first_b)
{
	sa(first_a);
	sb(first_b);
}

/*Pushes the top element of B's stack (push) to the top of A's (store) stack*/
void	pa(d_node **store, d_node **push)
{
	d_node	*new_first;
	d_node	*tmp;
	
	if (!(*push))
		return ;
	new_first = ft_lstnew((*push)->data);
	if (!new_first)
		return ;
	new_first->next = *store;
	new_first->prev = NULL;
	*store = new_first;
	tmp = *push;
	*push = (*push)->next;
	free(tmp);	
}

/*Pushes the top element of A's stack (push) to the top of B's (store) (store)*/
void	pb(d_node **store, d_node **push)
{
	pa(store, push);
}

/*Shift up all the nodes of stack A once*/
void	ra(d_node **stack_a) // juste un swap entre premier et dernier? ??
{
	d_node	*tmp;
	d_node	*first;
	
	first = *stack_a;
	while (*stack_a)
	{
		tmp = (*stack_a);
	}
}

int	main(void)
{
	d_node	*tst;
	d_node	*tst2;
	
	tst = ft_lstnew(0);
	tst->next = ft_lstnew(1);
	tst2 = ft_lstnew(1450);
	
	printf("TST DATA\n%d\n", tst->data);
	pa(&tst, &tst2);
	printf("TST DATA\n%d\n", tst->data);
	pb(&tst2, &tst);
	printf("TST2 DATA\n%d\n", tst2->data);
	printf("TST DATA\n%d\n", tst->data);
}