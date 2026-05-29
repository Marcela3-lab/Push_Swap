#include "push_swap.h"


int	main(int argc, char **argv)
{
	int		*res;
	int		size;
	t_stack	*a;
	t_stack	*b;
	int i;

	i= 0;
	
	res = splitmain(argc, argv, &size);

	if (!res)
		return (1);

	a = stack_init(res, size);
	while(i < argc - 1)
		{
			printf("Numero: %d ",res[i]);
			i++;
	}
	printf(" size = %d\n", size);
}	