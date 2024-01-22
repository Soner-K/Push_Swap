SRC			= 	src/instructions/instructions_a.c \
 				src/instructions/instructions_b.c \
				src/instructions/instructions.c \
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
				\
				src/printing/print_list.c \
				src/printing/visualize.c \
				\
				src/quicksort/create_tab.c \
				src/quicksort/quicksort.c \
				\
				src/binary_search/binary_search.c \
				\
				src/sorting/find_next_min.c \
				src/sorting/find_min.c \
				src/sorting/best_rotate_min.c \
				src/sorting/find_index_min.c \
				src/sorting/find_pairs.c \
				src/sorting/find_value.c \
				src/sorting/test.c \
				#src/sorting/best_rotate_pairs.c \
				src/sorting/best_remaining.c \

SRC_OBJ		= 	$(SRC:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	push_swap

all			:	$(NAME)

%.o			:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(SRC_OBJ)
				@$(CC) $(CFLAGS) $^ -o $@ -g

clean		:
				@rm -f $(SRC_OBJ) a.out

fclean		:	clean
				@rm -f $(NAME)

tidy		:	$(NAME) clean

re			:	fclean all