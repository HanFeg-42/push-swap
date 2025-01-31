/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:27:34 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/31 15:28:54 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*small_node(t_stack *lst)
{
	t_stack	*min;

	init_position(lst);
	min = lst;
	while (lst)
	{
		if (lst->next && min->data > lst->next->data)
			min = lst->next;
		lst = lst->next;
	}
	return (min);
}

void	push_small_node(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	smallest = small_node(*a);
	while (smallest->data != (*a)->data)
	{
		if (smallest->position < lst_size(*a) / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
}

void	sort_less_than_five(t_stack **a,t_stack **b)
{
	if (lst_size(*a) == 2)
	{
		if (!is_sorted(*a))
			sa(a, 1);
	}
	else if (lst_size(*a) <= 5)
	{
		if (is_sorted(*a))
			return ;
		push_small_node(a, b);
		sort_less_than_five(a, b);
		pa(a, b, 1);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac < 2 || !check_args(&a, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (is_sorted(a))
		return (lst_clear(&a), lst_clear(&b), 1);
	a->size = lst_size(a);
	a->bubble = malloc(a->size);
	free(a->bubble);
	if (a->size <= 5)
		sort_less_than_five(&a, &b);
	else
		sort_stack(&a, &b);
	return (lst_clear(&a), lst_clear(&b), 0);
}
