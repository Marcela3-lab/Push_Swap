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

int	verificar_erros(char *res, int size)
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
		if (!num_valid(res[i]))
			printf("O numero nao e valido");

		numero = (long)res[i];

		if (numero > INT_MAX || numero < INT_MIN)
			printf("Overflow");

		numbers[i] = (int)numero;
		
		
		if (num_duplicate(numbers, size))
			printf("duplicado");
		i++;
	}

	

	return (0);
}