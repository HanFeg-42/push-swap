#include "push_swap.h"

void    ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*bubble_sort(t_stack **a)
{
	int (i), (j);
	int *arr;
	t_stack *head;

	head = *a;

	(head)->size = lst_size(head);
	// int siz = (head)->size;
	arr = (int *)malloc((head)->size * sizeof(int));
	i = 0;
	while (head)
	{
		arr[i] = head->data;//printf("|%d==>",arr[i]);
		head = head->next;
		i++;
	}
	i = 0;
	// printf("head->size ==%d==\n", siz);exit(9);
	head = *a;
	while (i <= head->size)
	{
		j = 0;
		while (j < head->size - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	return (arr);
}

void    sort_stack(t_stack **a, t_stack **b)
{
	(void)b;
	int i;

	// (*a)->size = lst_size(*a);
	// (*a)->bubble = malloc((*a)->size);
	int *arr = bubble_sort(a);
	i = 0;
	while(i < (*a)->size)
	{
		printf("%d==>",arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
}