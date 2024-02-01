/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:17:35 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 14:51:12 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Sorts a stack of size three. Can sort for for a size of two.
 * @param a Adress of the pointer to the first node of stack A.
 * @returns void.
 */
void	sort_for_three(t_node **a)
{
	char	pos_max;

	pos_max = find_max_pos(*a);
	if (pos_max == 0)
		ra(a, 1);
	else if (pos_max == 1)
		rra(a, 1);
	if ((*a)->data > (*a)->next->data)
		sa(a, 1);
}
