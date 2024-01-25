/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:07:26 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/25 18:46:39 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
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
	int				data;
	int				*sorted;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef void		(*t_exec)(t_node **, t_node **);

typedef void		(*t_exec_swap)(t_node **);

typedef struct s_ins
{
	char			instruction;
	char			error;
	int				value;
	long			times;
}					t_ins;

t_node				*ft_lstnew(int data);
t_node				*ft_lstlast(t_node *lst);
t_node				*ft_lstfirst(t_node *lst);
void				add_node(t_node **node, t_node *insert);
void				clear_list(t_node **lst, char free_sorted);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_back(t_node **lst, t_node *new);
void				print_list(t_node *first_a, t_node *first_b);
char				*ft_fuse(char *s1, char *s2);
int					ft_strlen(char *s);
int					len_tab(char **av);
int					min(int a, int b);
int					max(int a, int b, char *changed);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr(char *s);

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

void				do_it_one(t_node **stack, t_exec_swap swap_one);
void				do_it_two(t_node **a, t_node **b, t_exec ins, long times);

// algorithm
t_ins				best_rotate(t_node *lst, int value);
t_ins				*best_pairs(t_node *lst, int *sorted, int last, long size);
long				find_pos_in_stack(t_node *lst, int value);
long				find_index_min(t_node *lst, int *sorted, int last);
void				exec_rotate(t_node **stack_a, t_node **stack_b, t_ins *ins);
void				exec_push(t_node **stack_a, t_node **stack_b, char push_b);
void				sort_for_three(t_node **stack_a);
long				find_cost(t_node *stack_a, t_node *stack_b);
long				find_closest_pos(int value, t_node *stack_b);
#endif