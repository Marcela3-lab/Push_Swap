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
			return (printf("Error\n"), 1);
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

int	*splitmain(int argc, char **argv, int *size)
{
	int		i;
	char	**res;
	int		*numbers;
	int total;

	total = 0;
	*size = 0;
	i = 1;
	while (i < argc)
	{
		res = split_args(argv[i], ' ');
		total += count_args(res);
		i++;
	}
	numbers = malloc(sizeof(int) * total);
	i = 1;
	if (!numbers)
		return (NULL);
	while (i < argc)
	{
		res = split_args(argv[i], ' ');
		if (!res || numbers_verifications(res, numbers, size))
			return (NULL);
	i++;
	}
	return (numbers);
}