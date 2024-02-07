SRC					= 	srcs/push_swap/execute/exec.c \
						\
						srcs/push_swap/instructions/push.c \
						srcs/push_swap/instructions/reverse_rotate.c \
						srcs/push_swap/instructions/rotate.c \
						srcs/push_swap/instructions/swap.c \
						\
						srcs/push_swap/parsing/create_list.c \
						srcs/push_swap/parsing/ft_atol.c \
						srcs/push_swap/parsing/ft_calloc.c \
						srcs/push_swap/parsing/ft_clear.c \
						srcs/push_swap/parsing/ft_error.c \
						srcs/push_swap/parsing/ft_split.c \
						srcs/push_swap/parsing/to_string.c \
						\
						srcs/push_swap/utils/clear_list.c \
						srcs/push_swap/utils/ft_bzero.c \
						srcs/push_swap/utils/ft_fuse.c \
						srcs/push_swap/utils/ft_lstadd_back.c \
						srcs/push_swap/utils/ft_lstadd_front.c \
						srcs/push_swap/utils/ft_lstlast.c \
						srcs/push_swap/utils/ft_lstnew.c \
						srcs/push_swap/utils/ft_lstsize.c \
						srcs/push_swap/utils/ft_min.c \
						srcs/push_swap/utils/ft_putstr.c \
						srcs/push_swap/utils/ft_quit.c \
						srcs/push_swap/utils/ft_strlen.c \
						\
						srcs/push_swap/sorting/adjusted_instructions.c \
						srcs/push_swap/sorting/find_positions.c \
						srcs/push_swap/sorting/smallest_cost_to_a.c \
						srcs/push_swap/sorting/smallest_cost_to_b.c \
						srcs/push_swap/sorting/sort_for_three.c \
						srcs/push_swap/sorting/sorting_alg.c \
						srcs/push_swap/sorting/to_top.c \

SRC_BONUS			=	srcs/checker_files/checker_utils.c \
						srcs/checker_files/checker.c \
						srcs/checker_files/get_next_line.c \

SRC_MAIN			=	srcs/push_swap/sorting/main.c

SRC_OBJ				= 	$(SRC:.c=.o)

SRC_OBJ_BONUS		= 	$(SRC_BONUS:.c=.o)

SRC_OBJ_MAIN		=	$(SRC_MAIN:.c=.o)

CC					=	cc

CFLAGS				=	-Wall -Wextra -Werror -g3

NAME				=	push_swap

CHECKER				=	checker

GREEN				= \033[32m

BLUE				= \033[34m

RED					= \033[31m

YELLOW				= \033[33m

COLOR_END			=	\033[0m



all					:	$(NAME)

%.o					:	%.c
						@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)				:	$(SRC_OBJ) $(SRC_OBJ_MAIN)
						@echo "$(BLUE)Compiling main files...$(COLOR_END)"
						$(CC) -g $(CFLAGS) $^ -o $@
						@echo "$(GREEN)Main project successfully compiled. Have fun !$(COLOR_END)"

bonus				:	$(SRC_OBJ) $(SRC_OBJ_BONUS)
						@echo "$(BLUE)Compiling bonus files...$(COLOR_END)"
						$(CC) $(CFLAGS) $^ -o $(CHECKER)
						@echo "$(GREEN)Bonus project successfully compiled. Have fun !$(COLOR_END)"
clean				:
						rm -f $(SRC_OBJ) $(SRC_OBJ_BONUS) $(SRC_OBJ_MAIN) a.out *.o
						@echo "$(RED)Object files removed$(COLOR_END)"

fclean				:	clean
						rm -f $(NAME) $(CHECKER)
						@echo "$(RED)Executable files removed$(COLOR_END)"

tidy				:	$(NAME) clean

both				:	all bonus

re					:	fclean all