/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:11:55 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/04 15:55:42 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Used to free a char** */
void	clear(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

/*As the name suggests, this functions's goal
is to store all the strings of av inside one string only*/
char	*to_string(int ac, char **av)
{
	char	*str;

	str = NULL;
	av++;
	if (!av || ac == 1)
		return (NULL);
	ac--;
	while (ac--)
	{
		str = ft_fuse(str, *av++);
		str = ft_fuse(str, " ");
	}
	return (str);
}

/*Transforming a string into a long, so that I can check later
if the value returned is bigger/smaller than INT_MAX/INT_MIN.*/
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

/*Checks if there's only valid numbers (only int values, no duplicates)*/
char	error(char **tab)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (tab[i])
	{
		if (ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN)
			return (clear(tab), 1);
		while (tab[j])
		{
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
				return (clear(tab), 1);
			if (ft_atol(tab[j]) == 0 && tab[j][0] != '0')
				return (clear(tab), 1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

/*Creates the list that will be used later, if the arguments are valid,
which is checked by the error function.*/
d_node	*create_list(int ac, char **av)
{
	d_node	*lst;
	d_node	*first;
	char	**tab;
	int		i;

	tab = ft_split((to_string(ac, av)), ' ');
	if (!tab)
		return (NULL);
	if (ac == 1 || error(tab))
	// cas ou tab[i] = nombre+caracteres (ex : 7a) ?
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	i = 0;
	lst = ft_lstnew(ft_atol(tab[i++]));
	if (!lst)
		return (NULL);
	first = lst;
	while (tab[i])
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atol(tab[i++])));
		lst = lst->next;
	}
	lst->next = NULL;
	return (clear(tab), first);
}

int	main(int ac, char **av)
{
	d_node *lst;

	lst = create_list(ac, av);
	if (!lst)
		return (0);
	print_list(lst, NULL);
	clear_list(&lst);
}