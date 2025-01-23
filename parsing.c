#include "push_swap.h"

char	**get_args(char **av)
{
	char	*join;
	char	*tmp;
	char	**split;
	int	i;

	//join every arg with a space
	i = 1;
	while (av[i])
	{
		av[i] = ft_strjoin(av[i], " ");//free 3afak
		i++;
	}
	join = ft_strdup("");
	//joining the args to each other
	i = 1;
	while (av[i])
	{
		tmp = join;
		join = ft_strjoin(join, av[i]);
		free(tmp);
		free(av[i]);
		i++;
	}
	split = ft_split(join, ' ');
	return (free(join), split);
}

int	is_arg_valid(char *nbr)
{
	int	i;
	long	number;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	if (nbr[i] == '\0')
		return (false);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (false);
		i++;
	}
	number = ft_atol(nbr);
	if (number < INT_MIN || number > INT_MAX)
		return (false);
	return (true);
}

int	is_duplicated(t_stack *a, char *nbr)
{
	t_stack	*curr;

	if (!a)
		return (true);
	curr = a;
	while (curr)
	{
		if(curr->data == ft_atoi(nbr))
			return (false);
		curr = curr->next;
	}
	return (true);
}

int	check_args(t_stack **a, char **av)
{
	t_stack	*new;
	char **args;
	int i;

	if (!a)
		return (false);
	args = get_args(av); // join and split them
	i = 0;
	while(args[i])
	{
		//hna feeen kaywqe3 si7r wa chokran
		if (!is_arg_valid(args[i]))
			return (cleanup(args), lst_clear(a), false);
		if(!is_duplicated(*a, args[i]))
			return (cleanup(args), lst_clear(a), false);
		new = lst_new(ft_atoi(args[i]));
		lst_addback(a, new);
		i++;
	}
	return (cleanup(args), true);
}

void	cleanup(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// int	check_args(t_stack **a, char **av)
// {
// 	char	*join;
// 	char	**split;
// 	bool	is_OK;

// 	join = join_args(av);
// 	is_OK = true;
// 	split = split_args(join, &is_OK); // 1 3 dog -- --4 65gh77 a +--3b 7 0
// 	free(join);
// 	// must atoi the list;
// 	if (is_OK)
// 	{
// 		init_stack(&a, split);// use atoi
// 		is_repeated(*a, &is_OK);
// 		if (is_OK)
// 			is_integer(*a, &is_OK);
// 	}
// 	if (!is_OK)
// 		lst_clear(a);
// 	return (cleanup(split), is_OK);
// }

// char	*join_args(char **av)
// {
// 	char	*join;
// 	char	*tmp;
// 	int	i;

// 	//join every arg with a space
// 	i = 1;
// 	while (av[i])
// 	{
// 		av[i] = ft_strjoin(av[i], " ");//free 3afak
// 		i++;
// 	}
// 	join = ft_strdup("");
// 	//joining the args to each other
// 	i = 1;
// 	while (av[i])
// 	{
// 		tmp = join;
// 		join = ft_strjoin(join, av[i]);
// 		free(tmp);
// 		i++;
// 	}
// 	return (join);
// }

// char	**split_args(char *join, bool *is_ok)
// {
// 	char	**split;
// 	int	(i), (j);

// 	split = ft_split(join, ' ');
// 	if (!split)
// 		return(*is_ok = false, NULL);
// 	i = 0;
// 	while (split[i])
// 	{
// 		j = 0;
// 		while (split[i][j])
// 		{
// 			if (split[i][j] == '+' || split[i][j] == '-')
// 				j++;
// 			if (split[i][j] == '\0')  //should be while
// 					return (*is_ok = false, split);
// 			while (split[i][j])// check - +
// 			{
// 				if (split[i][j] < '0' || split[i][j] > '9') //should be while
// 					return (*is_ok = false, split);
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (*is_ok = true, split);
// }



// void	init_stack(t_stack ***a, char **split)
// {
// 	int	i;
// 	t_stack	*new;

// 	if (!split)
// 		return ;
// 	i = 0;
// 	while (split[i])
// 	{
		// new = lst_new(ft_atoi(split[i]));
		// lst_addback(&a, new);
// 		i++;
// 	}
// }

// void	is_repeated(t_stack *a, bool *is_ok)
// {
// 	t_stack	*tmp;
// 	t_stack	*curr;

// 	tmp = a;
// 	while (tmp)
// 	{
// 		curr = tmp->next;
// 		while (curr != NULL)
// 		{
// 			if (curr->data == tmp->data)
// 			{
// 				*is_ok = false;
// 				return ;
// 			}
// 			curr = curr->next;
// 		}
// 		tmp = tmp->next;
// 	}
// 	*is_ok = true;
// }

// void	is_integer(t_stack *a, bool *is_ok)
// {
// 	t_stack	*tmp;

// 	tmp = a;
// 	while (tmp)
// 	{
// 		if (tmp->data < INT_MIN || tmp->data > INT_MAX)
// 		{
// 			*is_ok = false;
// 			return ;
// 		}
// 		tmp = tmp->next;
// 	}
// 	*is_ok = true;
// }
//TO_DO =>-------------------- join_args -/
//TO_DO =>-------------------- split_args -/
//TO_DO =>-------------------- init_stack -/
//TO_DO =>-------------------- is_repeated -/
//TO_DO =>-------------------- is_integer -/
//TO_DO =>-------------------- cleanup -/
