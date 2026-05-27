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

int	numbers_verifications(char **res, int *numbers, int *index)
{
	int			j;
	int			size;
	long long	num;

	size = count_args(res);
	j = 0;
	while (j < size)
	{
		if (!num_valid(res[j]))
			return (printf("Error\n"), 1);
		num = ft_atoi(res[j]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		numbers[*index] = (int)num;
		if (*index >= 1)
		{
			if (num_duplicate(numbers, *index))
				return (printf("Error\n"), 1);
		}
		(*index)++;
		j++;
	}
	return (0);
}

int	*splitmain(int argc, char **argv)
{
	int		i;
	int		index;
	char	**res;
	int		*numbers;

	index = 0;
	numbers = malloc(sizeof(int) * 1000);
	i = 1;
	while (i < argc)
	{
		res = split_args(argv[i], ' ');
		if (!res)
			return (NULL);
		if (numbers_verifications(res, numbers, &index))
			return (NULL);
		i++;
	}
	return (numbers);
}