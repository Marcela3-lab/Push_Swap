#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	jump_flags(char *argv)
{
	return (!ft_strcmp(argv, "--simple")
		|| !ft_strcmp(argv, "--medium")
		|| !ft_strcmp(argv, "--complex")
		|| !ft_strcmp(argv, "--adaptive")
		|| !ft_strcmp(argv, "--bench"));
}

static int	*return_numbers(char **argv, int argc, int *size)
{
	int		i;
	char	**tmp;

	i = 1;
	*size = 0;
	while (i < argc)
	{
		if (!jump_flags(argv[i]))
		{
			tmp = split_args(argv[i], ' ');
			if (!tmp)
				return (NULL);
			*size += count_args(tmp);
			free_split(tmp);
		}
		i++;
	}
	return (malloc(sizeof(int) * (*size)));
}

int	*splitfirst(int argc, char **argv, int *size)
{
	int		i;
	int		index; // da para reduzir a funcao retirando esta variavel?
	int		*numbers;
	char	**res;

	i = 1;
	index = 0;
	numbers = return_numbers(argv, argc, size);
	if (!numbers)
		return (NULL);
	while (i < argc)
	{
		if (!jump_flags(argv[i]))
		{
			if (!num_valid(argv[i]))
				return (free(numbers), NULL);
			res = split_args(argv[i], ' ');
			if (!res)
				return (free(numbers), NULL);
			if (numbers_verifications(res, numbers, &index))
				free_and_exit(res, numbers);
			free_split(res);
		}
		i++;
	}
	return (numbers);
}
