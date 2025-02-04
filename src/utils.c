/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 04:41:08 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/04 15:16:05 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	incr_segment(int *start, int *end, int size)
{
	if (*end < size - 1)
		(*end)++;
	if (*start < size - 2)
		(*start)++;
}

void	init_position(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->position = i;
		lst = lst->next;
		i++;
	}
}

void	init_bubble_size(t_stack *lst, int *arr)
{
	int	size;

	size = lst_size(lst);
	while (lst)
	{
		if (size <= 100)
			lst->gold = size / 6;
		else
			lst->gold = size / 14;
		lst->bubble = arr;
		lst = lst->next;
	}
}
