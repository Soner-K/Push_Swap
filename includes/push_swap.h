/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:07:26 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 21:29:08 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define LONG_MAX 9223372036854775807
# define NO_CONVERSION 0

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
	long			data;
	int				*sorted;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_cost
{
	int				times_f;
	int				times_s;
	char			ins_f;
	char			ins_s;
	char			error;
}					t_cost;

typedef struct s_sizes
{
	long			lstsize_a;
	long			lstsize_b;
}					t_sizes;

typedef void		(*t_exec)(t_node **, t_node **);

typedef void		(*t_exec_one)(t_node **);

t_node				*ft_lstnew(int data);
t_node				*ft_lstlast(t_node *lst);
t_node				*ft_lstfirst(t_node *lst);
void				clear_list(t_node **lst);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_back(t_node **lst, t_node *new);
void				print_list(t_node *first_a, t_node *first_b);
char				*ft_fuse(char *s1, char *s2);
int					ft_strlen(char *s);
int					len_tab(char **av);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr(char *s, int fd);
int					min(int a, int b);
void				ft_quit(void);

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
long				ft_lstsize(t_node *lst);

// sorting and finding
int					*create_tab(int ac, char **av, int *size_tab);
void				quicksort(int *tab, int low, int high);
int					*create_and_sort(int ac, char **av, int size);
long				binary_search(int *tab, long right, long value);

void				do_it_one(t_node **stack, t_exec_one ins, long times);
void				do_it_two(t_node **a, t_node **b, t_cost set);

void				do_it_second(t_node **a, t_node **b, t_cost set);
void				do_it_first(t_node **a, t_node **b, t_cost set);

// algorithm
long				find_pos_in_stack(t_node *lst, long value);
long				find_max_pos(t_node *stack);
long				find_min_pos(t_node *stack);
void				sort_for_three(t_node **stack_a);
t_cost				new_rotate(t_cost a, t_cost b);
t_cost				new_reverse_rotate(t_cost a, t_cost b);
t_cost				smallest_cost_to_b(t_node *a, t_node *b, t_sizes sizes);
t_cost				smallest_cost_to_a(t_node *a, t_sizes sizes, long value);
long				closest_smallest_in_b(int value, t_node *stack_b);
long				closest_biggest_in_a(int value, t_node *stack_a);
t_cost				to_top(long pos, long lstsize, char a);
void				sort(t_node **a, t_node **b, t_sizes *sizes);
char				is_sorted(t_node *lst);
#endif