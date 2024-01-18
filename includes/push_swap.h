/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:07:26 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/18 17:22:39 by sokaraku         ###   ########.fr       */
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

# define SA 1
# define SB 2
# define SS 3

# define RA 4
# define RB 5
# define RR 6

# define RRA 7
# define RRB 8
# define RRR 9

# define PA 10
# define PB 11

typedef struct s_node
{
	int				data;
	int				*sorted;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_min
{
	int				value;
	size_t			gap;
}					t_min;

typedef struct s_pairs
{
	int				first;
	int				second;
	int				pos_first;
	int				pos_second;
	long			gap;
}					t_pairs;

// typedef struct s_ins
// {
// 	char			instruction_f;
// 	int				times_f;
// 	char			instruction_s;
// 	int				times_s;
// 	char			error;
// }					t_ins;

typedef struct s_ins
{
	char			instruction;
	int				times;
	char			error;
}					t_ins;

t_node				*ft_lstnew(int data);
t_node				*ft_lstlast(t_node *lst);
t_node				*ft_lstfirst(t_node *lst);
void				add_node(t_node **node, t_node *insert);
void				clear_list(t_node **lst, char binary);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_back(t_node **lst, t_node *new);
void				print_list(t_node *first_a, t_node *first_b);
char				*ft_fuse(char *s1, char *s2);
int					ft_strlen(char *s);
int					len_tab(char **av);
int					min(int a, int b);
int					max(int a, int b, char *changed);

void				play(int ac, char **av);

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
t_node				*create_list(int ac, char **av, int i);
void				clear(char **tab);
int					ft_lstsize(t_node *lst);

// sorting and finding
int					*create_tab(int ac, char **av, int *size_tab);
void				quicksort(int *tab, int low, int high);
int					*create_and_sort(int ac, char **av, int size);
int					binary_search(int *tab, int right, int value);

// algorithm
t_min				find_next_min(t_node *lst);
t_min				find_min(t_node *lst, int *sorted, int size);
t_ins				best_rotate_min(t_node *lst, char *mode, int size);
long				find_index_min(t_node *lst, int *sorted, int last);
t_pairs				find_pairs(t_node *lst, int *sorted, int last);
t_ins				best_rotate_pairs(t_node *lst, t_pairs pairs);
t_ins				best_remaining(t_node *lst, int lstsize, int last);
t_ins				find_value(t_node *lst, int value, size_t i);

int					ft_strcmp(const char *s1, const char *s2);
#endif