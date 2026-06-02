#include "../push_swap.h"
#include <limits.h>

int	num_duplicate(int *arr, int j)
{
	int	i;

	i = j - 1;
	
		while (i >= 0 )
		{
			if (arr[i] == arr[j])
		{
			return (1);
		}
		i--;		
	}
	return 0;
}
// 
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
		{
			return (0);
		}
		i++;
	}
	return (1);
}

t_flags verificar_flags(int argc, char **argv)
{
	int i;
	t_flags flags;

	i = 1;
	flags.has_flags = 0;
	flags.has_bench = 0;
	flags.strategy = start_adaptive;

	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
		{
			flags.strategy = start_simple;
			flags.has_flags = 1;
		}
		else if (ft_strcmp(argv[i], "--medium") == 0)
		{
			flags.strategy = start_medium;
			flags.has_flags = 1;
		}
		else if (ft_strcmp(argv[i], "--complex") == 0)
		{
			flags.strategy = start_complex;
			flags.has_flags = 1;
		}
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
		{
			flags.strategy = start_adaptive;
			flags.has_flags = 1;
		}
		else if (ft_strcmp(argv[i], "--bench") == 0)
		{
			flags.has_bench = 1;
		}
		i++;
	}
	return (flags);
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
		num = ft_atoi(res[j]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error();
		numbers[*index] = (int)num;

		if (*index >= 1)
		{
			if (num_duplicate(numbers, *index))
				ft_error();
		}
		(*index)++;
		j++;
	}
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	int		i;
// 	int res;
// 	int arr[] = {4, 6, 42};

// 	i = 1;
// 	// while (i < argc)
// 	// {
		
// 	// 	i++;
// 	// }
// 	res = num_duplicate(arr, 2);
// 	printf("%d",res);
// 	return (0);
// }