#include "push_swap.h"

t_stack	*lst_new(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = nbr;
	new->next = NULL;
	return (new);
}

void	lst_addfront(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*lst_last(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	lst_addback(t_stack **lst, t_stack *new)
{
	t_stack *last;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = lst_last(*lst);
	last->next = new;
}

void	lst_delone(t_stack *lst)
{
	if (!lst)
		return ;
	//free(lst->data);
	free(lst);
}

void	lst_clear(t_stack **lst)
{
	t_stack *tmp;
	t_stack	*next;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		lst_delone(tmp);
		tmp = next;
	}
	*lst = NULL;
}

int	lst_size(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

//TO-DO => ----------------------------lst_new -/
//TO-DO => ----------------------------lst_addfront -/
//TO-DO => ----------------------------lst_addback -/
//TO-DO => ----------------------------lst_last-/
//TO-DO => ----------------------------lst_clear-/
//TO-DO => ----------------------------lst_size -/
//TO-DO => ----------------------------lst_delone-/
