#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;
	int		total;
	char	**res;
	int index;

	index = 0;
	total = 0;
	i = 1;
	while (i < argc)
	{
		res = split_args(argv[i], ' ');
		if (!res)
			return (1);
		total += count_args(res);
		i++;
	}
	int *numbers;
	numbers = malloc(sizeof(int) * total);	
	i = 1;
	while (i < argc)
	{
		res = split_args(argv[i], ' ');
		if (!res)
			return (1);

		size = count_args(res);
		j = 0;

		while (j < size)
		{
			if (!num_valid(res[j]))
				return (printf("Error\n"), 1);
			numbers[index++] = ft_atoi(res[j]);
			j++;
		}
		i++;
	}
	if (num_duplicate(numbers, total))
		return (printf("Error\n"), 1);
	i = 0;
	while (i < total)
	{
		printf("numero = %d\n", numbers[i]);
		i++;
	}
	return (0);
}