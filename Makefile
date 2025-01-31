NAME		=	push_swap
BONUS_NAME	=	checker
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM		=	rm -f
SRC		=	 algorithm.c ft_atoi.c     push.c             push_swap.c   rrotate.c  utils2.c  ft_split.c  linked_list.c    parsing.c   rotate.c   swap.c     utils.c
B_SRC		=	push_swap_bonus.c  ft_atoi.c     push.c    rrotate.c  utils2.c  ft_split.c  linked_list.c    parsing.c   rotate.c   swap.c     utils.c get_next_line.c

OBJ		=	${SRC:.c=.o}
B_OBJ		=	${B_SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(BONUS_NAME)
clean:
	$(RM) $(OBJ) $(B_OBJ)
fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
re: fclean all
.PHONY: clean all fclean bonus re
