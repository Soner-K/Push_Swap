SRC			= 	src/instructions/instructions_a.c \
 				src/instructions/instructions_b.c \
				src/instructions/instructions.c \
				src/parsing/parsing.c \
				src/parsing/ft_bzero.c \
				src/parsing/ft_calloc.c \
				src/parsing/ft_split.c \
				src/parsing/parsing.c \
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
				src/printing/print_list.c \
				src/printing/visualize.c \
				src/merge_sort/create_tab.c \

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