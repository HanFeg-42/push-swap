NAME	=	push_swap
SRC	=	main.c\
		linked_list.c\
		parsing.c
OBJ	=	${SRC:.c=.o}
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	libft/libft.a

#rules

all: $(NAME)

# ma3rftch kindir n compiler libft

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "compiled successfully"

clean:

fclean:
	@rm $(NAME)

re:

