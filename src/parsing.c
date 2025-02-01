/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 04:50:34 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/01 13:34:16 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**get_args(char **av)
{
	char	*join;
	char	*tmp;
	char	**split;
	int		i;

	i = 1;
	while (av[i])
	{
		av[i] = ft_strjoin(av[i], " ");
		i++;
	}
	join = ft_strdup("");
	i = 1;
	while (av[i])
	{
		tmp = join;
		join = ft_strjoin(join, av[i]);
		free(tmp);
		free(av[i]);
		i++;
	}
	split = ft_split(join, ' ');
	return (free(join), split);
}

int	is_arg_valid(char *nbr)
{
	int			i;
	long long	number;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	if (nbr[i] == '\0')
		return (false);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (false);
		i++;
	}
	if ((ft_strlen(nbr) > 11 && ft_atoi(nbr) == -1))
		return (false);
	number = ft_atol(nbr);
	if (number < INT_MIN || number > INT_MAX)
		return (false);
	return (true);
}

int	is_duplicated(t_stack *a, char *nbr)
{
	t_stack	*curr;

	if (!a)
		return (true);
	curr = a;
	while (curr)
	{
		if (curr->data == ft_atoi(nbr))
			return (false);
		curr = curr->next;
	}
	return (true);
}

int	check_args(t_stack **a, char **av)
{
	t_stack	*new;
	char	**args;
	int		i;

	if (!a)
		return (false);
	if (!is_exist(av))
		return (false);
	args = get_args(av);
	i = 0;
	while (args[i])
	{
		if (!is_arg_valid(args[i]))
			return (cleanup(args), lst_clear(a), false);
		if (!is_duplicated(*a, args[i]))
			return (cleanup(args), lst_clear(a), false);
		new = lst_new(ft_atoi(args[i]));
		lst_addback(a, new);
		i++;
	}
	return (cleanup(args), true);
}

void	cleanup(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
