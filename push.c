/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 05:09:25 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/29 05:16:15 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*=========--pa--=====--pb--===========*/

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	if (!b || !(*b))
		return ;
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!a || !(*a))
		return ;
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
