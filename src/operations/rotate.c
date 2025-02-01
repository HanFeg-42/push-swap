/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 05:09:29 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/01 13:34:45 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
//------------rotate--------------

void	rotate(t_stack **a)
{
	t_stack	*last;

	last = lst_last(*a);
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a, int check)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	rotate(a);
	if (check)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, int check)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	rotate(b);
	if (check)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, int check)
{
	if ((!a || !(*a) || !(*a)->next) || (!b || !(*b) || !(*b)->next))
		return ;
	ra(a, 0);
	rb(b, 0);
	if (check)
		ft_putstr_fd("rr\n", 1);
}
