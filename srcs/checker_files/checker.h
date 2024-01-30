/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:41:23 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/30 18:11:12 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include "../../includes/push_swap.h"

void	execute(char *str, t_node **stack_a, t_node **stack_b);
void	free_and_maybe_out(t_node **a, t_node **b, char quit);
int		ft_check(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*file_to_keep(int fd, char *keep, int *bytes_read);
char	*keep_to_line(char *keep);
char	*remove_from_keep(char *line, char *keep);
char	*get_next_line(int fd, char binary);
#endif