#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i = 0;

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

int	*return_numbers(char **argv, int argc, int *size)
{
	int		i = 1;
	char	**tmp;

	*size = 0;
	while (i < argc)
	{
		if (!jump_flags(argv[i]))
		{
			tmp = split_args(argv[i], ' ');
			if (!tmp)
				return (NULL);
			*size += count_args(tmp);
			free_spl(tmp);
		}
		i++;
	}
	return (malloc(sizeof(int) * (*size)));
}

int	*splitfirst(int argc, char **argv, int *size)
{
	int		i = 1;
	int		index = 0;
	int		*numbers;
	char	**res;

	numbers = return_numbers(argv, argc, size);
	if (!numbers)
		return (NULL);

	while (i < argc)
	{
		if (!jump_flags(argv[i]))
		{
			res = split_args(argv[i], ' ');
			if (!res)
				return (free(numbers), NULL);
			if (numbers_verifications(res, numbers, &index))
				return (free_spl(res), free(numbers), NULL);
			free_spl(res);
		}
		i++;
	}
	return (numbers);
}