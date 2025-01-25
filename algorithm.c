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

void	incr_segment(t_stack *a)
{
	if (a->end < a->size - 1)
		a->end++;
	if (a->start < a->size - 2)
		a->start++;
}

void	phase_1(t_stack	**a, t_stack **b)
{
	int i;

	i = 0;
	while (*a)
	{
		if ((*a)->data < (*a)->bubble[(*a)->start])
		{
			//chii tmjnina
			//handli awl case
			pb(a, b);
			rb(b, 1);
			incr_segment(*a);
		}
		else if ((*a)->data < (*a)->bubble[(*a)->end])
		{
			// another tmjnina -- awl mra handliha
			pb(a, b);
                        if(*a && *b && (*b)->next && (*b)->next->data > (*b)->data)
                                sb(b, 1);
                        incr_segment(*a);
		}
		else
		{
			// last tmjnina	
			ra(a, 1);
		}
		(*a) = (*a)->next;
	}
}
// zidi wahed lfunction smiha " is stack empty" it s gonna help a lot
void	phase_2(t_stack **a, t_stack **b)
{
	t_stack *biggest;

	while(!is_stack_empty(*b))
	{
		biggest = big_node(**a);
		if (biggest->up_down)
			pa(a, b);
		else
		{
			rrb(b, 1);
			pa(a, b);
		}
	}
}
// wa handli a zmer chmiiit rwina fhad lcode 3ndk
void	init_gold(t_stack *lst)
{
	if (lst->size <= 100)
		lst->gold = lst->size / 6;
	else
		lst->gold = lst->size / 14;
	lst->start = 0;
	lst->end = lst->gold;
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
	i = 0;
	phase_1(a, b);
	phase_2(a, b);
	while(i < (*a)->size)
	{
		printf("%d==>",arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
}
