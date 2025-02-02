/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:27:34 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/02 15:17:52 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac < 2 || !check_args(&a, av))
		return (ft_putstr_fd("Error\n", 2), 2);
	if (is_sorted(a))
		return (lst_clear(&a), lst_clear(&b), 3);
	a->size = lst_size(a);
	a->bubble = malloc(a->size);
	free(a->bubble);
	if (a->size <= 5)
		sort_less_than_five(&a, &b);
	else
		sort_stack(&a, &b);
	return (lst_clear(&a), lst_clear(&b), 0);
}
