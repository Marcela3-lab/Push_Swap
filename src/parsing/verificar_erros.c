#include "push_swap.h"
#include <limits.h>

int	num_duplicate(int *arr, int j)
{
	int	i;

	i = j - 1;
	
		while (i >= 0 )
		{
			if (arr[i] == arr[j])
		{
			printf("Num duplicado");
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
			printf("numero nao e digito");
			return (0);
		}
			
		i++;
	}
	
	return (1);
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