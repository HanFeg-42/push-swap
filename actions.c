/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 02:47:38 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/16 20:35:19 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap(t_stack **a)
// {
// 	t_stack	*tmp;

// 	if (a->next != NULL)
// 	{
// 		tmp = ft_lstnew(a->data);
// 		a->data = a->next->data;
// 		a->next>data = tmp->data; // zidi les ***
// 	}
// }

/*=========--sa--=========--sb--============*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack **a, int check)
{
	if (!a)
		return ;
	if (!(*a) || !(*(a)->next))
		return ;
	ft_swap(*(a)->data, *(a)->next->data);
	if (check)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int ckeck)
{
	sa(**b, 0);
	if (check)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(**a, 0);
	sb(**b, 0);
	ft_putstr_fd("ss\n", 1);
}

/*=========--pa--=====--pb--===========*/

void	push(t_stack **a, t_stack **b)
{
	t_stack	*head;

	head = a;
}
