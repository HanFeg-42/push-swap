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

	//(*a)->size = lst_size(*a);
	head = *a;
	arr = (int *)malloc((head)->size * sizeof(int));
	i = 0;
	while (head)
	{
		arr[i] = head->data;
		head = head->next;
		i++;
	}
	i = 0;
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

void	incr_segment(int *start, int *end, int size)
{
	if (*end < size - 1)
		(*end)++;
	if (*start < size - 2)
		(*start)++;
}

void	phase_1(t_stack	**a, t_stack **b)
{
	int start;
	int end;

	start = 0;
	end = (*a)->gold;
	int size = (*a)->size;
	while (*a)
	{
		if ((*a)->data <= (*a)->bubble[start])
		{
			pb(a, b);
			rb(b, 1);
			incr_segment(&start, &end, size);
		}
		else if ((*a)->data <= (*a)->bubble[end])
		{
			pb(a, b);
			if(*b && (*b)->next && (*b)->next->data > (*b)->data)
				sb(b, 1);
			incr_segment(&start, &end, size);
		}
		else
			ra(a, 1);
	}
}

void	init_position(t_stack *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst->position = i;
		lst = lst->next;
		i++;
	}
}

t_stack	*big_node(t_stack *lst)
{
	t_stack *max;
	int size;
	int (i), (x);

	size = lst_size(lst);
	init_position(lst);
	max = lst;
	i = 0;
	x = true;
	while (lst)
	{
		i++;
		if (lst->next && max->data < lst->next->data)
		{
			max = lst->next;
			if(i < size / 2)
				max->up_down = 1;
			else
				max->up_down = 0;
			x = false;
		}
		lst = lst->next;
	}
	//printf("max = %d\n", max->data);
	if (x)
		max->up_down = 1;
	return (max);
}

// zidi wahed lfunction smiha " is stack empty" it s gonna help a lot
void	phase_2(t_stack **a, t_stack **b)
{
	t_stack *biggest;

	while(*b)
	{
		biggest = big_node(*b);
		while (biggest->data != (*b)->data)
		{
			if (biggest->up_down)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		pa(a, b);
	}
}
// wa handli a zmer chmiiit rwina fhad lcode 3ndk
void	init_gold(t_stack *lst)
{
	while (lst)
	{
		if (lst->size <= 100)
			lst->gold = lst->size / 6;
		else
			lst->gold = lst->size / 14;
		lst->start = 0;
		lst->end = lst->gold;
		lst = lst->next;
	}
}

void	init_bubble_size(t_stack *lst, int *arr)
{
	int size;

	size = lst_size(lst);
	while (lst)
	{
		if (lst->size <= 100)
			lst->gold = lst->size / 6;
		else
			lst->gold = lst->size / 14;
		lst->start = 0;
		lst->end = lst->gold;
		lst->bubble = arr;
		lst->size = size;
		lst = lst->next;
	}
}

void    sort_stack(t_stack **a, t_stack **b)
{
	// t_stack *current;

	int *arr = bubble_sort(a);
	(*a)->bubble = arr;
	init_gold(*a);
	init_bubble_size(*a, arr);
	phase_1(a, b);
	// current = *b;
	// while(current)
	// {
	// 	printf("%d-->", current->data);
	// 	current = current->next;
	// }
	// printf("\n");
	phase_2(a, b);
	free(arr);
}
