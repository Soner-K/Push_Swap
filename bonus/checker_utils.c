/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:13:24 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/28 18:58:43 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
step 0 : check erreurs
step 1 : stocker la liste
step 2 : stocker les commandes (ou les executer?)
step 3 : verifier que liste ok
*/

void	free_and_out(t_node **a, t_node **b, char quit)
{
	clear_list(a);
	clear_list(b);
	if (quit == 1)
		ft_quit();
}

int	ft_check(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (s[0] == '\n')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	execute(char *str, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strcmp(str, "sa\n"))
		return (lst_swap(stack_a));
	if (!ft_strcmp(str, "sb\n"))
		return (lst_swap(stack_b));
	if (!ft_strcmp(str, "ss\n"))
		return (lst_swap(stack_a), lst_swap(stack_b));
	if (!ft_strcmp(str, "pa\n"))
		return (lst_push(stack_a, stack_b));
	if (!ft_strcmp(str, "pb\n"))
		return (lst_push(stack_b, stack_a));
	if (!ft_strcmp(str, "ra\n"))
		return (lst_rotate(stack_a));
	if (!ft_strcmp(str, "rb\n"))
		return (lst_rotate(stack_b));
	if (!ft_strcmp(str, "rrr\n"))
		return (lst_reverse_rotate(stack_a), lst_reverse_rotate(stack_b));
	if (!ft_strcmp(str, "rr\n"))
		return (lst_rotate(stack_a), lst_rotate(stack_b));
	if (!ft_strcmp(str, "rra\n"))
		return (lst_reverse_rotate(stack_a));
	if (!ft_strcmp(str, "rrb\n"))
		return (lst_reverse_rotate(stack_b));
	free_and_out(stack_a, stack_b, 1);
	return (0);
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
