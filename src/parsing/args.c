#include "../push_swap.h"

int	count_args(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	return (i);
}

char	**split_args(char *arg, char c)
{
	return (ft_split(arg, c));
}

