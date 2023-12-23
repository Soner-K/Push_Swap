/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:07:26 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/23 15:26:00 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					d_node;

d_node				*ft_lstnew(int data);
void				add_node(d_node **node, d_node *insert);
void				clear_list(d_node **node);
d_node				*ft_lstlast(d_node *node);
void				ra(d_node **stack_a);
void				pa(d_node **store, d_node **push);
void				ss(d_node **first_a, d_node **first_b);
void				sb(d_node **first_b);
void				sa(d_node **first_a);
void				rra(d_node **first_node);
void				rrb(d_node **first_node);
void				rrr(d_node **first_a, d_node **first_b);
void				ft_lstadd_front(d_node **lst, d_node *new);
void				ft_lstadd_back(d_node **lst, d_node *new);
#endif