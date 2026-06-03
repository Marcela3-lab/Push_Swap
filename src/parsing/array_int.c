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
	if (ft_strcmp(argv, "--simple") == 0
		|| ft_strcmp(argv, "--medium") == 0
		|| ft_strcmp(argv, "--complex") == 0
		|| ft_strcmp(argv, "--adaptive") == 0
		|| ft_strcmp(argv, "--bench") == 0)
		return (1);
	return (0);
}

int	*return_numbers(char **argv, int argc, int *size)
{
	int	i;
	int	*numbers;

	i = 0;
	*size = 0;
	while (i < argc)
	{
		if (jump_flags(argv[i]))
			i++;
		else
		{
			*size += count_args(split_args(argv[i], ' '));
			i++;
		}
	}
<<<<<<< HEAD
	numbers = malloc(sizeof(int) * (*size));
=======
	numbers = malloc(sizeof(int) * (*size)); //malloc
	i = 1;
>>>>>>> db9e6fb0705fa681df65b26b98c895dd530823d3
	if (!numbers)
		return (NULL);
	return (numbers);
}

int	*splitfirst(int argc, char **argv, int *size)
{
	int		i;
	int		index;
	int		*numbers;
	char	**res;

	i = 1;
	index = 0;
	numbers = return_numbers(argv, argc, size);
	while (i < argc)
	{
		if (!jump_flags(argv[i]))
		{
			res = split_args(argv[i], ' ');
			if (!res || numbers_verifications(res, numbers, &index))
			{
				free_spl(res);
				return (NULL);
			}
			free_spl(res);
		}
<<<<<<< HEAD
=======
		res = split_args(argv[i], ' '); // malloc
		if (!res || numbers_verifications(res, numbers, &index))
			return (NULL);
		// free_split(res);
>>>>>>> db9e6fb0705fa681df65b26b98c895dd530823d3
		i++;
	}
	return (numbers);
}
