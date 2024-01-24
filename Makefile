SRC			= 	src/instructions/push.c \
 				src/instructions/swap.c \
				src/instructions/rotate.c \
				src/instructions/reverse_rotate.c \
				\
				src/parsing/parsing.c \
				src/parsing/ft_bzero.c \
				src/parsing/ft_calloc.c \
				src/parsing/ft_split.c \
				src/parsing/parsing.c \
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
				src/utils/ft_lstfirst.c \
				src/utils/create_and_sort.c \
				src/utils/min.c \
				src/utils/max.c \
				src/utils/ft_putstr.c \
				\
				src/printing/print_list.c \
				src/printing/visualize.c \
				\
				src/quicksort/create_tab.c \
				src/quicksort/quicksort.c \
				\
				# src/sorting/best_rotate.c \
				# src/sorting/find_pos_in_stack.c \
				# src/sorting/find_index_min.c \
				# src/sorting/best_pairs.c \
				# src/sorting/exec_instruction.c \

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