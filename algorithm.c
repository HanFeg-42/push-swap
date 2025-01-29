/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 03:49:08 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/29 04:07:11 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*bubble_sort(t_stack *a)
{
	int		*arr;
	t_stack	*head;
	int		i;
	int		j;

	head = a;
	arr = (int *)malloc((head)->size * sizeof(int));
	i = 0;
	while (head)
	{
		arr[i++] = head->data;
		head = head->next;
	}
	i = 0;
	while (i++ <= a->size)
	{
		j = 0;
		while (j < a->size - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
	}
	return (arr);
}

void	incr_segment(int *start, int *end, int size)
{
	if (*end < size - 1)
		(*end)++;
	if (*start < size - 2)
		(*start)++;
}

void	phase_1(t_stack	**a, t_stack **b)
{
	int (size), (end), (start);

	start = 0;
	end = (*a)->gold;
	size = lst_size(*a);
	while (*a)
	{
		if ((*a)->data <= (*a)->bubble[start])
		{
			pb(a, b);
			rb(b, 1);
			incr_segment(&start, &end, size);
		}
		else if ((*a)->data <= (*a)->bubble[end])
		{
			pb(a, b);
			if(*b && (*b)->next && (*b)->next->data > (*b)->data)
				sb(b, 1);
			incr_segment(&start, &end, size);
		}
		else
			ra(a, 1);
	}
}

void	init_position(t_stack *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst->position = i;
		lst = lst->next;
		i++;
	}
}

t_stack	*big_node(t_stack *lst)
{
	t_stack *max;

	init_position(lst);
	max = lst;
	while (lst)
	{
		if (lst->next && max->data < lst->next->data)
			max = lst->next;

		lst = lst->next;
	}
	return (max);
}

// zidi wahed lfunction smiha " is stack empty" it s gonna help a lot
void	phase_2(t_stack **a, t_stack **b)
{
	t_stack *biggest;

	while (*b)
	{
		biggest = big_node(*b);
		while (biggest->data != (*b)->data)
		{
			if(biggest->position < lst_size(*b) / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		pa(a, b);
	}
}
// wa handli a zmer chmiiit rwina fhad lcode 3ndk

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

void	sort_stack(t_stack **a, t_stack **b)
{
	(*a)->bubble = bubble_sort(*a);
	init_bubble_size(*a, (*a)->bubble);
	phase_1(a, b);
	phase_2(a, b);
	free((*a)->bubble);
}
