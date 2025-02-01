NAME		=	push_swap
BONUS_NAME	=	checker
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3
RM			=	rm -f
SRC			=	src/push_swap.c src/sort_big_num.c src/sort_small_num.c src/utils.c src/parsing.c src/parsing_utils.c src/linked_list.c\
				src/operations/push.c src/operations/rrotate.c src/operations/rotate.c src/operations/swap.c\
				libft/ft_atoi.c libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_strlen.c\
				libft/ft_isdigit.c libft/ft_split.c libft/ft_strjoin.c libft/ft_substr.c\
				libft/ft_strchr.c libft/ft_strncmp.c
B_SRC		=	src_bonus/push_swap_bonus.c src_bonus/get_next_line.c\
				libft/ft_atoi.c libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_strlen.c\
				libft/ft_isdigit.c libft/ft_split.c libft/ft_strjoin.c libft/ft_substr.c\
				libft/ft_strchr.c libft/ft_strncmp.c\
				src/parsing.c src/parsing_utils.c src/utils.c src/linked_list.c\
				src/operations/push.c src/operations/rrotate.c src/operations/rotate.c src/operations/swap.c
OBJ			=	${SRC:.c=.o}
B_OBJ		=	${B_SRC:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled Successfully"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(B_OBJ)
	@$(CC) $(CFLAGS) $(B_OBJ) -o $(BONUS_NAME)
	@echo "Bonus Compiled Successfully"
clean:
	@$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean all fclean bonus re
