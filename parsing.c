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
		init_stack(a, split);
		is_repeated(a, &is_OK);
		if (is_OK)
			is_integer(a, &is_OK);
	}
	return (is_OK);
}
