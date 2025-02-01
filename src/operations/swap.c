/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 05:09:35 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/01 13:35:00 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	sa(t_stack **a, int check)
{
	if (!a || !(*a) || !((*a)->next))
		return ;
	swap(a);
	if (check)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int check)
{
	if (!b || !(*b) || !((*b)->next))
		return ;
	swap(b);
	if (check)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, int check)
{
	if ((!a || !(*a) || !(*a)->next) || (!b || !(*b) || !(*b)->next))
		return ;
	sa(a, 0);
	sb(b, 0);
	if (check)
		ft_putstr_fd("ss\n", 1);
}
