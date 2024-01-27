SRC			= 	src/instructions/push.c \
 				src/instructions/swap.c \
				src/instructions/rotate.c \
				src/instructions/reverse_rotate.c \
				\
				src/parsing/ft_bzero.c \
				src/parsing/ft_calloc.c \
				src/parsing/ft_split.c \
				src/parsing/create_list.c \
				src/parsing/clear.c \
				src/parsing/error.c \
				src/parsing/ft_atol.c \
				src/parsing/to_string.c \
				\
				src/utils/clear_list.c \
				src/utils/ft_fuse.c \
				src/utils/ft_lstadd_front.c \
				src/utils/ft_lstlast.c \
				src/utils/ft_lstadd_back.c \
				src/utils/ft_lstnew.c \
				src/utils/ft_lstsize.c \
				src/utils/ft_strcmp.c \
				src/utils/ft_strlen.c \
				src/utils/len_tab.c \
				src/utils/ft_putstr.c \
				src/utils/min.c \
				src/utils/quit.c \
				\
				src/execute/exec.c \
				\
				src/sorting/alg_three.c \
				src/sorting/smallest_cost_to_b.c \
				src/sorting/smallest_cost_to_a.c \
				src/sorting/to_top.c \
				src/sorting/find_positions.c \
				src/sorting/adjusted_instructions.c \
				src/sorting/sorting.c \
				src/sorting/main.c \
				
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