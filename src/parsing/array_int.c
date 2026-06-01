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
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_flags verificar_flags(int argc, char **argv)
{
	int i;
	t_flags flags;

	i = 1;
	flags.has_flags = 0;
	flags.has_bench = 0;
	flags.strategy = 0;

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
	int			size; // index ja e o size, acho que nao precisamos desta variavel
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
	int			i;
	char		**res;
	int			*numbers;
	int			index;

	i = 1;
	*size = 0;
	index = 0;
	
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0
			|| ft_strcmp(argv[i], "--medium") == 0
			|| ft_strcmp(argv[i], "--complex") == 0
			|| ft_strcmp(argv[i], "--adaptive") == 0
			|| ft_strcmp(argv[i], "--bench") == 0)
		{
			i++;
			continue;
		}
		*size += count_args(split_args(argv[i], ' '));
		i++;
	}

	numbers = malloc(sizeof(int) * (*size));
	i = 1;
	if (!numbers)
		return (NULL);

	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0
			|| ft_strcmp(argv[i], "--medium") == 0
			|| ft_strcmp(argv[i], "--complex") == 0
			|| ft_strcmp(argv[i], "--adaptive") == 0
			|| ft_strcmp(argv[i], "--bench") == 0)
		{
			i++;
			continue;
		}
		res = split_args(argv[i], ' ');
		if (!res || numbers_verifications(res, numbers, &index))
			return (NULL);
		// free_split(res);
		i++;
	}
	return (numbers);
}
