/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:07:26 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/11 15:36:42 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define NO_CONVERSION 0 /**/

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

t_node				*ft_lstnew(int data);
t_node				*ft_lstlast(t_node *node);
void				add_node(t_node **node, t_node *insert);
void				clear_list(t_node **node);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_back(t_node **lst, t_node *new);
t_node				*create_list(int ac, char **av);
void				print_list(t_node *first_a, t_node *first_b);
char				*ft_fuse(char *s1, char *s2);
int					ft_strlen(char *s);
int					len_tab(char **av);

// instructions
void				sa(t_node **first_a);
void				sb(t_node **first_b);
void				ss(t_node **first_a, t_node **first_b);
void				pa(t_node **store, t_node **push);
void				pb(t_node **store, t_node **push);
void				ra(t_node **stack_a);
void				rb(t_node **first_node);
void				rr(t_node **first_a, t_node **first_b);
void				rra(t_node **first_node);
void				rrb(t_node **first_node);
void				rrr(t_node **first_a, t_node **first_b);

// parsing
long				ft_atol(const char *nptr);
char				error(char **tab);
char				**ft_split(char const *s, char c);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
char				*to_string(int ac, char **av);
void				clear(char **tab);
int					ft_lstsize(t_node *lst);

int					*create_tab(int ac, char **av);
void				quicksort(int *tab, int low, int high);

int					binary_search(int *tab, int right, int value);

void				execute(char *str, t_node **stack_a, t_node **stack_b);
int					ft_strcmp(const char *s1, const char *s2);
#endif