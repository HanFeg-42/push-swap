NAME	=	push_swap
SRC	=	main.c\
		linked_list.c\
		parsing.c\
		moves.c
OBJ	=	${SRC:.c=.o}
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
LIBFT_DIR = ./libft
LIBFT	=	libft/libft.a

#rules

all: $(NAME)

# ma3rftch kindir n compiler libft


$(NAME): $(SRC)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "compiled successfully"

clean:

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm $(NAME)

re: fclean all

