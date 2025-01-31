NAME	=	push_swap
B_NAME	=	checker
SRC	=	main.c\
		linked_list.c\
		parsing.c\
		rotate.c rrotate.c push.c swap.c\
		algorithm.c utils.c utils2.c ft_atoi.c ft_split.c
B_SRC	=	bonus/main.c\
                linked_list.c\
                parsing.c\
                rotate.c rrotate.c push.c swap.c\
                ft_atoi.c ft_split.c utils.c utils2.c get_next_line.c

OBJ	=	${SRC:.c=.o}
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
# -fsanitize=address -g3
# LIBFT_DIR = ./libft
# LIBFT	=	libft/libft.a
BONUS_DIR	=	./bonus


#rules

all: $(NAME)

# ma3rftch kindir n compiler libft
bonus: $(B_NAME)

$(B_NAME): $(B_SRC)
	@$(CC) $(CFLAGS) $(B_SRC) -o $(B_NAME)
	@echo "bonus compiled successfully"

# $(NAME): $(SRC)
# 	@$(MAKE) -C $(LIBFT_DIR)
# 	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
# 	@echo "compiled successfully"

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "comiled successfully"

clean:

# fclean:
# 	@$(MAKE) -C $(LIBFT_DIR) fclean
# 	@rm $(NAME)

re: fclean all

