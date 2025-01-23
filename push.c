#include "push_swap.h"
/*=========--pa--=====--pb--===========*/

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	// if (!(*a))
	// {
	// 	*a = *b;
	// }
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	if (!b)
		return ;
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}
void	pb(t_stack **a, t_stack **b)
{
	if (!a)
		return ;
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}