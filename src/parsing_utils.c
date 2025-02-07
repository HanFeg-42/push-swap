/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:22:46 by hfegrach          #+#    #+#             */
/*   Updated: 2025/02/06 09:55:00 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_spaces(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ' && av[i] != '\t')
			return (true);
		i++;
	}
	return (false);
}

int	is_exist(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_strlen(av[i]) || !check_spaces(av[i]))
			return (false);
		i++;
	}
	return (true);
}

int	special_case(char *av)
{
	int	i;

	i = 1;
	if (av[0] == '-')
	{
		while (av[i])
		{
			if (av[i] == '1' && av[i + 1] == '\0')
				return (true);
			if (av[i] == '0')
				i++;
			else
				break ;
		}
	}
	return (false);
}
