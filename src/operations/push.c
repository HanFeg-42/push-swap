/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 05:09:25 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/01 13:34:38 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pa(t_stack **a, t_stack **b, int check)
{
	if (!b || !(*b))
		return ;
	push(a, b);
	if (check)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b, int check)
{
	if (!a || !(*a))
		return ;
	push(b, a);
	if (check)
		ft_putstr_fd("pb\n", 1);
}
