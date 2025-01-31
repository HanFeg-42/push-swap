/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:35:37 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/31 00:38:19 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int				size;
	int				*bubble;
	int				position;
	int				gold;
	int				up_down;
}	t_stack;

// function prototype
//------parcing.c-----------------------------------
int		check_args(t_stack **a, char **av);
int		is_sorted(t_stack *a);
void	cleanup(char **str);
int		not_OK(char **av);
//-------linked_list---------------------------------
t_stack	*lst_new(int nbr);
t_stack	*lst_last(t_stack *lst);
void	lst_addback(t_stack **lst, t_stack *new);
void	lst_clear(t_stack **lst);
int		lst_size(t_stack *lst);
//-------------------moves-----------------------
void	sa(t_stack **a, int check);
void	sb(t_stack **b, int check);
void	ss(t_stack **a, t_stack **b, int check);
void	pa(t_stack **a, t_stack **b, int check);
void	pb(t_stack **a, t_stack **b, int check);
void	ra(t_stack **a, int check);
void	rb(t_stack **b, int check);
void	rr(t_stack **a, t_stack **b, int check);
void	rra(t_stack **a, int check);
void	rrb(t_stack **b, int check);
void	rrr(t_stack **a, t_stack **b, int check);

//-----------------algo--------------------------
void	sort_stack(t_stack **a, t_stack **b);
int		*bubble_sort(t_stack *a);
void	phase_1(t_stack	**a, t_stack **b);
t_stack	*big_node(t_stack *lst);
void	phase_2(t_stack **a, t_stack **b);
void	ft_swap(int *a, int *b);
void	incr_segment(int *start, int *end, int size);
void	init_position(t_stack *lst);
void	init_bubble_size(t_stack *lst, int *arr);

//--------------utils-----------------------------
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
long long	ft_atol(const char *a);
int			ft_atoi(const char *a);
size_t		ft_strlen(const char *str);
int     	ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);

//-------------gnl----------------------------
char    *get_next_line(int fd);
void    check_move(char *line, t_stack **a, t_stack **b);
void    apply_moves(t_stack **a, t_stack **b);
int		is_sorted(t_stack *a);


#endif
