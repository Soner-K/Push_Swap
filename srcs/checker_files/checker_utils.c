/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:13:24 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 18:11:45 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_and_maybe_out(t_node **a, t_node **b, char quit)
{
	clear_list(a);
	clear_list(b);
	if (quit == 1)
		ft_quit();
}

void	execute(char *str, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strcmp(str, "sa\n"))
		return (sa(stack_a, 0));
	if (!ft_strcmp(str, "sb\n"))
		return (sb(stack_b, 0));
	if (!ft_strcmp(str, "ss\n"))
		return (ss(stack_a, stack_b, 0));
	if (!ft_strcmp(str, "pa\n"))
		return (pa(stack_a, stack_b, 0));
	if (!ft_strcmp(str, "pb\n"))
		return (pb(stack_b, stack_a, 0));
	if (!ft_strcmp(str, "ra\n"))
		return (ra(stack_a, 0));
	if (!ft_strcmp(str, "rb\n"))
		return (rb(stack_b, 0));
	if (!ft_strcmp(str, "rrr\n"))
		return (rrr(stack_a, stack_b, 0));
	if (!ft_strcmp(str, "rr\n"))
		return (rr(stack_a, stack_b, 0));
	if (!ft_strcmp(str, "rra\n"))
		return (rra(stack_a, 0));
	if (!ft_strcmp(str, "rrb\n"))
		return (rrb(stack_b, 0));
	return (free(str), free_and_maybe_out(stack_a, stack_b, 1));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;

	i = 0;
	s1_cp = (unsigned char *)s1;
	s2_cp = (unsigned char *)s2;
	while ((s1[i] || s2[i]))
	{
		if (s1_cp[i] != s2_cp[i])
			return (s1_cp[i] - s2_cp[i]);
		i++;
	}
	return (0);
}
