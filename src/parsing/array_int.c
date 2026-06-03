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

int	*splitfirst(int argc, char **argv, int *size)
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
	numbers = malloc(sizeof(int) * (*size)); //malloc
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
		res = split_args(argv[i], ' '); // malloc
		if (!res || numbers_verifications(res, numbers, &index))
			return (NULL);
		// free_split(res);
		i++;
	}
	return (numbers);
}
