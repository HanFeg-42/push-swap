/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:24:05 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/29 09:20:09 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_moves(t_stack **a, t_stack **b)
{
	// while (condition)
	// {
		//read using get_next_line move bye move
		// check_move(line);
		// {
		//		if (strcmp(line, "sa"))
		//			sa(x, y);
		//		else if ..
		//		....
		// } whithout writing ok
	// }
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
	// apply_moves(&a, &b);
	if (is_sorted(a))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
