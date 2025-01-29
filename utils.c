/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 04:41:08 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/29 05:23:17 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
		if (lst->size <= 100)
			lst->gold = lst->size / 6;
		else
			lst->gold = lst->size / 14;
		lst->bubble = arr;
		lst->size = size;
		lst = lst->next;
	}
}
