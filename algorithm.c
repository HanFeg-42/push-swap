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

	(*a)->size = lst_size(*a);
	head = *a;
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

void	incr_segment(int *start, int *end, int size)
{
	if (*end < size - 1)
		(*end)++;
	if (*start < size - 2)
		(*start)++;
}
int	is_stack_empty(t_stack *lst)
{
	if(lst->next == NULL)
		return (true);
	return (false);
}

void	phase_1(t_stack	**a, t_stack **b)
{
	int start;
	int end;
	t_stack *curr;

	start = 0;
	end = (*a)->gold;
	int size = (*a)->size;
	while ((*a))
	{
		printf("machi hna whadi *a = %d\n", (*a)->data);
		printf("machi hna whadi start = %d\n", start);
		if ((*a)->data < (*a)->bubble[start])
		{
			//chii tmjnina
			//handli awl case
			pb(a, b);
			rb(b, 1);
			incr_segment(&start, &end, size);
		}
		else if ((*a)->data < (*a)->bubble[end])
		{
			// another tmjnina -- awl mra handliha
			pb(a, b);
			if(*a && *b && (*b)->next && (*b)->next->data > (*b)->data)
				sb(b, 1);
			incr_segment(&start, &end, size);
		}
		else
		{
			// last tmjnina
			ra(a, 1);
		}
		// (*a) = (*a)->next;
	}
	pb(a, b);
	printf("test\n");
	curr = *b;
	while(curr)
	{
		printf("%d==>>", curr->data);
		curr = curr->next;
	}
	printf("\n");
}
t_stack	*big_node(t_stack *head)
{
	t_stack *max;
	t_stack *lst;
	int i;

	lst = head;
	head->size = lst_size(head);
	max = lst;
	i = 0;
	while (lst)
	{
		if (max->data < lst->next->data)
		{
			max = lst->next;
			if(i < head->size / 2)
				max->up_down = 1;
			else
				max->up_down = 0;
		}
		lst = lst->next;
		i++;
	}
	printf("max = %d\n", max->data);
	return (max);
}
// zidi wahed lfunction smiha " is stack empty" it s gonna help a lot
void	phase_2(t_stack **a, t_stack **b)
{
	t_stack *biggest;

	while(*b)
	{
		biggest = big_node(*b);
		if (biggest->up_down)
			pa(a, b);
		else
		{
			rrb(b, 1);
			pa(a, b);
		}
		*b = (*b)->next;
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
	(void)b;
	int i;

	// (*a)->size = lst_size(*a);
	// (*a)->bubble = malloc((*a)->size);
	int *arr = bubble_sort(a);
	(*a)->bubble = arr;
	init_gold(*a);
	init_bubble_size(*a, arr);
	i = 0;
	while(i < (*a)->size)
	{
		printf("%d==>",arr[i]);
		i++;
	}
	printf("\n");
	phase_1(a, b);
	phase_2(a, b);
	free(arr);
}
