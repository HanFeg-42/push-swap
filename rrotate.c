#include "push_swap.h"
//=========Reverse rotate==============

t_stack	*lst_blast(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (NULL);
	last = lst;
	while (last->next->next)
		last = last->next;
	return (last);
}

void	r_rotate(t_stack **a)
{
	t_stack	*b_last;
	t_stack	*last;

	b_last = lst_blast(*a);
	last = lst_last(*a);
	last->next = *a;
	*a = last;
	b_last->next = NULL;
}
void	rra(t_stack **a, int check)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	r_rotate(a);
	if (check)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int check)
{
	if (!b || !(*b) || !(*b)->next)
		return ;
	r_rotate(b);
	if (check)
		ft_putstr_fd("rrb\n", 1);
}
void	rrr(t_stack **a, t_stack **b)
{
	if ((!a || !(*a) || !(*a)->next) || (!b || !(*b) || !(*b)->next))
		return ;
	rra(a, 0);
	rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}