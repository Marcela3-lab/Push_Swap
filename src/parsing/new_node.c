#include "push_swap.h"

char	**split_args(char *arg, char c)
{
	char	**res;

	res = ft_split(arg, c);
	return (res);
}

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	int		j;
// 	char	**res;
// 	int		num;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		res = split_args(argv[i], ' ');

// 		if (!res)
// 			return (1);
// 		j = 0;
// 		while (res[j])
// 		{
// 			num = ft_atoi(argv[i]);
// 			printf("numero = %d\n", num);
			
// 			if (verificar_erros(&res[j], argc - 1))
// 			{
// 				printf("erro");
				
// 			}
// 			j++;
// 		}
// 		i++;
// 	}

// 	return (0);
// }