/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:11:55 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/23 18:14:19 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	num;
	int		i;
	char	sign;

	num = 0;
	i = 0;
	sign = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += (int)(nptr[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-num);
	return (num);
}

char	error(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (av[i])
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			if (ft_atol(av[j]) == 0 && av[j][0] != '0')
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

d_node	*create_list(int ac, char **av)
{
	d_node	*lst;
	d_node	*first;
	int		i;

	if (ac == 1 || error(av))
	// cas ou av[i] = nombre+caracteres (ex : 7a) ?
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	i = 1;
	lst = ft_lstnew(ft_atol(av[i++]));
	if (!lst)
		return (NULL);
	first = lst;
	ac -= 2;
	while (ac--)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atol(av[i])));
		lst = lst->next;
		i++;
	}
	lst->next = NULL;
	lst = first;
	return (lst);
}

// int	main(int ac, char **av)
// {
// 	d_node *lst;

// 	lst = create_list(ac, av);
// 	if (!lst)
// 		return (0);
// 	print_list(lst);
// 	clear_list(&lst);
// }