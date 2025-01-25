#include "push_swap.h"

// void	swap(t_stack **a)
// {
// 	t_stack	*tmp;

// 	tmp = NULL;
// 	tmp = lst_new((*a)->data);
// 	(*a)->data = (*a)->next->data;
// 	(*a)->next->data = tmp->data; // zidi les ***
// 	free(tmp);
// }

void	swap(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

/*=========--sa--=========--sb--============*/

// void	ft_swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

void	sa(t_stack **a, int check)
{
	if (!a || !(*a) || !((*a)->next))
		return ;
	swap(a);
	if (check)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int check)
{
	if (!b || !(*b) || !((*b)->next))
		return ;
	swap(b);
	if (check)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	if ((!a || !(*a) || !(*a)->next) || (!b || !(*b) || !(*b)->next))
		return ;
	sa(a, 0);
	sb(b, 0);
	ft_putstr_fd("ss\n", 1);
}
