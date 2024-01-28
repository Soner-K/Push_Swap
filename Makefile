SRC			= 	src/execute/exec.c \
				\
				src/instructions/push.c \
				src/instructions/reverse_rotate.c \
				src/instructions/rotate.c \
 				src/instructions/swap.c \
				\
				src/parsing/create_list.c \
				src/parsing/ft_atol.c \
				src/parsing/ft_calloc.c \
				src/parsing/ft_clear.c \
				src/parsing/ft_error.c \
				src/parsing/ft_split.c \
				src/parsing/to_string.c \
				\
				src/utils/clear_list.c \
				src/utils/ft_lstadd_back.c \
				src/utils/ft_lstadd_front.c \
				src/utils/ft_lstlast.c \
				src/utils/ft_lstnew.c \
				src/utils/ft_lstsize.c \
				src/utils/ft_min.c \
				src/utils/ft_putstr.c \
				src/utils/ft_quit.c \
				src/utils/ft_strlen.c \
				\
				src/sorting/adjusted_instructions.c \
				src/sorting/find_positions.c \
				src/sorting/main.c \
				src/sorting/smallest_cost_to_a.c \
				src/sorting/smallest_cost_to_b.c \
				src/sorting/sort_for_three.c \
				src/sorting/sorting.c \
				src/sorting/to_top.c \
				
SRC_OBJ		= 	$(SRC:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	push_swap

all			:	$(NAME)

%.o			:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(SRC_OBJ)
				@$(CC) -g $(CFLAGS) $^ -o $@

clean		:
				@rm -f $(SRC_OBJ) a.out *.o

fclean		:	clean
				@rm -f $(NAME) nowall

tidy		:	$(NAME) clean

nowall		:	$(SRC_OBJ)
				@$(CC) $^ -o $@ -g

re			:	fclean all