/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rev_sorted_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:19:38 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/04 15:17:14 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_rev_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data < a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}

void	sort_rev_sorted(t_stack **a, t_stack **b)
{
	while (*a)
	{
		pb(a, b, 1);
		rb(b, 1);
	}
	while (*b)
		pa(a, b, 1);
}
