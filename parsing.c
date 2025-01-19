#include "push_swap.h"

int	check_args(t_stack **a, int ac, char **av)
{
	char	*join;
	char	**split;
	bool	is_OK;

	join = join_args(ac, av);
	is_OK = true;
	split = split_args(join, &is_OK); // 1 3 dog -- --4 65gh77 a +--3b 7 0
	free(join);
	// must atoi the list;
	if (is_OK)
	{
		init_stack(a, split); // use atoi
		is_repeated(a, &is_OK);
		if (is_OK)
			is_integer(a, &is_OK);
	}
	return (free(join), cleanup(split), is_OK);
}

char	*join_args(int ac, char **av)
{
	char	*join;
	char	*tmp;
	int	i;

	//join every arg with a space
	i = 1;
	while (av[i++])
		av[i] = ft_strjoin(av[i], " ");
	join = ft_strdup("");
	//joining the args to each other
	i = 1;
	while (av[i])
	{
		tmp = join;
		join = ft_strjoin(join, av[i]);
		free(tmp);
		i++;
	}
	return (join);
}

char	**split_args(char *join, bool *is_ok)
{
	char	**split;
	int	i;

	split = ft_split(join, ' ');
	if (!split)
		return(*is_ok = 0, NULL);
	i = 0;
	while (split[i])
	{
		if (check_sign(split[i]))

	}
}
//TO_DO =>-------------------- join_args
//TO_DO =>-------------------- split_args
//TO_DO =>-------------------- init_stack
//TO_DO =>-------------------- is_repeated
//TO_DO =>-------------------- is_integer

