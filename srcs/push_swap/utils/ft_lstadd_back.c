/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:50:31 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 14:51:46 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->prev = ft_lstlast(*lst);
	ft_lstlast(*lst)->next = new;
}
