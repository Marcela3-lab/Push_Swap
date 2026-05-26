#include "push_swap.h"
#include <limits.h>

int	num_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	num_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;

	if (!str[i])
		return (0);

	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	verificar_erros(char **args, int size)
{
	int		i;
	long	numero;
	int		*numbers;

	i = 0;
	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (0);

	while (i < size)
	{
		if (!num_valid(args[i]))
			return (free(numbers), 0);

		numero = ft_atoi(args[i]);

		if (numero > INT_MAX || numero < INT_MIN)
			return (free(numbers), 0);

		numbers[i] = (int)numero;
		i++;
	}

	if (num_duplicate(numbers, size))
		return (free(numbers), 0);

	free(numbers);
	return (1);
}
int	main(int argc, char **argv)
{
	int		i;
	int arr[] = {4, 6, 3};

	i = 1;
	while (i < argc)
	{
		
		i++;
	}

	return (0);
}