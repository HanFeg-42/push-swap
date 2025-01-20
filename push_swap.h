/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:35:37 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/20 17:37:36 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int data;
	struct s_stack	*next;
}	t_stack;

// function prototype
//------parcing.c-----------------------------------
int	check_args(t_stack **a, char **av);
char	*join_args(char **av);
char	**split_args(char *join, bool *is_ok);
void	cleanup(char **str);
void	init_stack(t_stack ***a, char **split);
void	is_repeated(t_stack *a, bool *is_ok);
void	is_integer(t_stack *a, bool *is_ok);
//-------linked_list---------------------------------
t_stack	*lst_new(int nbr);
void	lst_addfront(t_stack **lst, t_stack *new);
t_stack	*lst_last(t_stack *lst);
void	lst_addback(t_stack ****lst, t_stack *new);
void	lst_delone(t_stack *lst);
void	lst_clear(t_stack **lst);
int	lst_size(t_stack *lst);

#endif
