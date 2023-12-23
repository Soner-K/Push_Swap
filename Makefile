SRC			= 	instructions_a.c \
 				instructions_b.c \
				instructions.c \
				parsing.c \
				test.c \
				utils.c \
				utils2.c \
				visualize.c

SRC_OBJ		= 	$(SRC:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	push_swap

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(SRC_OBJ)
				$(CC) $(CFLAGS) $^ -o $@

clean		:
				rm -f $(SRC_OBJ) a.out

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all