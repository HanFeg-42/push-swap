/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:35:37 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/29 05:37:27 by hfegrach         ###   ########.fr       */
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
void	cleanup(char **str);
//-------linked_list---------------------------------
t_stack	*lst_new(int nbr);
t_stack	*lst_last(t_stack *lst);
void	lst_addback(t_stack **lst, t_stack *new);
void	lst_clear(t_stack **lst);
int		lst_size(t_stack *lst);
//-------------------moves-----------------------
void	sa(t_stack **a, int check);
void	sb(t_stack **b, int check);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int check);
void	rb(t_stack **b, int check);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int check);
void	rrb(t_stack **b, int check);
void	rrr(t_stack **a, t_stack **b);

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

#endif
