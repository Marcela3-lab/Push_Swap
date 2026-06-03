#include "../push_swap.h"

void	free_split(char **res)
{
<<<<<<< HEAD
    write(2,"Error\n",6);
    return;
}
#include "../push_swap.h"

void	free_split(char **res)
{
=======
>>>>>>> c551ae3afcccf1241aa39bbe1ac762f3ab862bd7
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

void    free_and_exit(char **res, int *numbers)
{
	if (res)
		free_split(res);
	if (numbers)
		free(numbers);
	write(2, "Error\n", 6);
	exit(1);
}