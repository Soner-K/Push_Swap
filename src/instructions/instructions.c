/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:54 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/23 16:15:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*Does sa and sb at the same time (I'm using sa two times since I use it
anyway in rb so there's no need to call a function that will
call another one when I can call it directly).*/
void	ss(t_node **first_a, t_node **first_b, char *s)
{
	sa(first_a, NULL);
	sa(first_b, NULL);
	ft_putstr(s);
}

/* ra and rb.*/
void	rr(t_node **first_a, t_node **first_b, char *s)
{
	if (!(*first_a) || !(*first_b))
		return ;
	ra(first_a, NULL);
	ra(first_b, NULL);
	ft_putstr(s);
}

/*rra and rrb.*/
void	rrr(t_node **first_a, t_node **first_b, char *s)
{
	rra(first_a, NULL);
	rra(first_b, NULL);
	ft_putstr(s);
}
