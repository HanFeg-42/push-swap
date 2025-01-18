NAME	=	push_swap
SRC	=	main.c\
		actions.c\
		parsing.c
OBJ	=	${SRC:.c=.o}
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror

#rules

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "compiled successfully"

clean:

fclean:

re:

