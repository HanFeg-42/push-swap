/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:30:51 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/29 16:40:36 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
	{
		if (i == n - 1)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *a)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (a[i] == 32 || (a[i] >= 9 && a[i] <= 13))
		i++;
	if (a[i] == '-' || a[i] == '+')
	{
		if (a[i] == '-')
			sign *= -1;
		i++;
	}
	while (a[i] >= '0' && a[i] <= '9')
	{
		res = res * 10 + a[i] - '0';
		i++;
	}
	return ((int)(sign * res));
}

long long	ft_atol(const char *a)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (a[i] == 32 || (a[i] >= 9 && a[i] <= 13))
		i++;
	if (a[i] == '-' || a[i] == '+')
	{
		if (a[i] == '-')
			sign *= -1;
		i++;
	}
	while (a[i] >= '0' && a[i] <= '9')
	{
		res = res * 10 + a[i] - '0';
		i++;
	}
	return ((sign * res));
}
