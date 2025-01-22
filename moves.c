/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 02:47:38 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/20 17:46:19 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*tmp;

	if ((*a)->next != NULL)
	{
		tmp = ft_lstnew((*a)->data);
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp->data; // zidi les ***
	}
}

/*=========--sa--=========--sb--============*/

// void	ft_swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

void	sa(t_stack **a, int check)
{
	if (!a)
		return ;
	if (!(*a) || !((*a)->next))
		return ;
	swap(a);
	if (check)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int check)
{
	sa(b, 0);
	if (check)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_putstr_fd("ss\n", 1);
}

/*=========--pa--=====--pb--===========*/

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	if (!b)
		return ;
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}
void	pb(t_stack **a, t_stack **b)
{
	if (!a)
		return ;
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}

//------------rotate--------------

void	rotate(t_stack **a)
{
	t_stack *last;

	last = lst_last(*a);
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a, int check)
{
	rotate(a);
	if (check)
		ft_putstr_fd("ra\n", 1);
}
void	rb(t_stack **b, int check)
{
	rotate(b);
	if (check)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_putstr_fd("rr\n", 1);
}

//=========Reverse rotate==============

t_stack	*lst_blast(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (NULL);
	last = lst;
	while (last->next->next)
		last = last->next;
	return (last);
}

void	r_rotate(t_stack **a)
{
	t_stack	*b_last;
	t_stack	*last;

	b_last = lst_blast(*a);
	last = lst_last(*a);
	last->next = *a;
	*a = last;
	b_last->next = NULL;
}
void	rra(t_stack **a, int check)
{
	r_rotate(a);
	if (check)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int check)
{
	r_rotate(b);
	if (check)
		ft_putstr_fd("rrb\n", 1);
}
void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
// you need to protect ur functions wa chokran