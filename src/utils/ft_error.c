#include "../push_swap.h"


void	free_split(char **res)
{
	int	i;

	i = 0;
	if (!res)
		return ;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free (res);
}

void	free_and_exit(char **res, int *numbers)
{
	if (res)
		free_split(res);
	if (numbers)
		free(numbers);
	write(2, "Error\n", 6);
	exit(1);
}
