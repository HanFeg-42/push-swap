/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfegrach <hfegrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:27:34 by hfegrach          #+#    #+#             */
/*   Updated: 2025/01/25 06:20:44 by hfegrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	// t_stack	*current;

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
		return (1);
	sort_stack(&a, &b);
// 	(a)->size = lst_size(a);
//     (a)->bubble = malloc((a)->size);
// 	a->bubble[0] = 15;
// 	printf("bubble[%d] = %d\n", 0, a->bubble[0]);
// 	free((a)->bubble);
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	sa(&a, true);
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	ra(&a, true);
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	rra(&a, true);
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	pb(&a, &b);pb(&a, &b);pb(&a, &b);
// 	printf("====list A ====\n");
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	printf("====list B ====\n");
// 	current = b;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// sb(&b, true);
// 	// rrr(&a, &b);
// 	printf("====list A ====\n");
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	printf("====list B ====\n");
// 	current = b;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 		pa(&b, &a);pa(&b, &a); pa(&b, &a);
// 	printf("====list A ====\n");
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	printf("====list B ====\n");
// 	current = b;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	sa(&a, true);
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("nj7t sa t3iich\n");
// 	ra(&a, true);
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("nj7t ra t3iich\n");
// 	rra(&a, true);
// 	current = a;
// 	while(current)
// 	{
// 		printf("%d-->", current->data);
// 		current = current->next;
// 	}
// 	printf("nj7t rra t3iich\n");
	lst_clear(&a);
	lst_clear(&b);
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
