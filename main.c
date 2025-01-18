/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:27:34 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/18 12:00:02 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*current;

	if (!check_args(&a, ac, av))
		printf("Error\n");
	current = a;
	while(a->content)
	{
		printf("%d-->", current->content);
		current = current->next;
	}
	printf("\n");
	return (0);
}
