/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:24:05 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/02 22:49:57 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_move(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		return (false);
	return (true);
}

void	apply_moves(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0, 0);
	while (line)
	{
		if (!check_move(line, a, b))
		{
			ft_putstr_fd("Error\n", 2);
			lst_clear(a);
			lst_clear(b);
			free(line);
			get_next_line(0, 1);
			exit(1);
		}
		free(line);
		line = get_next_line(0, 0);
	}
	free(line);
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
		return (ft_putstr_fd("Error\n", 2), 1);
	apply_moves(&a, &b);
	if (is_sorted(a) && b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (lst_clear(&a), lst_clear(&b), 0);
}
