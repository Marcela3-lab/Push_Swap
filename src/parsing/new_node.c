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
			num = ft_atoi(argv[i]);

			printf("string = %s\n", res[j]);
			printf("numero = %d\n", num);
			j++;
			if (verificar_erros(res, argc - 1))
			{
				printf("erro");
				
			}
		}
		i++;
	}

	return (0);
}