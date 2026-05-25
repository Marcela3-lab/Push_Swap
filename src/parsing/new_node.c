#include "push_swap.h"


char	**split_args(char *arg, char c)
{
	char	**res;

	res = ft_split(arg, c);
	return (res);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**res;
	int		num;

	i = 1;
	while (i < argc)
	{
		res = split_args(argv[i], ' ');

		if (!res)
			return (1);
		j = 0;
		while (res[j])
		{
			num = ft_atoi(res[j]);

			printf("string = %s\n", res[j]);
			printf("numero = %d\n", num);
			j++;
		}
		i++;
	}

	return (0);

	i = 1;
	while (i < argc)
	{
		printf("ARG: %s\n", argv[i]);
		res = ft_split(argv[i], ' ');
		if (!res)
			return (1);
		j = 0;
		while (res[j])
		{
			printf("split[%d] = %s\n", j, res[j]);
			j++;
		}
		i++;
	}
	return (0);
}
