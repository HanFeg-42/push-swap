/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:27:34 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/20 15:51:55 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*current;

	a = NULL;
	if (ac == 1 || !check_args(&a, av))
	{
		printf("Error\n");
		return (1);
	}
	current = a;
	while(a)
	{
		printf("%d-->", current->data);
		current = current->next;
	}
	printf("\n");
	return (0);
}

// int main(int ac, char **av) {
//     t_stack *a = NULL; // Initialize stack pointer
//     t_stack *current = NULL;

//     // if (ac == 1 || !check_args(&a, av)) {
//     //     printf("Error\n");
//     //     return 1; // Exit gracefully on error
//     // }
// printf("hi %d\n", ac);
// check_args(&a, av);
// printf("hellows %d==\n", a->data);
//     // Use a separate pointer to traverse the stack
//     current = a;
//     while (current) {
// 		printf("whati whati ya lalla\n");
//         //printf("%d --> ", current->data); // Print data
//         current = current->next;         // Move to the next node
//     }
//     printf("NULL\n");

//     // Free allocated memory to prevent leaks


//     return 0;
// }


