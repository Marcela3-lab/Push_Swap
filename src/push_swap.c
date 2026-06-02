#include "push_swap.h"

int	main(int argc, char **argv)
{
	write(1, "main", 5);
	int		*res;
	int		size;
	t_data	data;

	res = splitfirst(argc, argv, &size);
	write(1, "1", 2);
	if (!res)
		return (1);
	ft_bzero(&data, sizeof(t_data));
	data.flags = verificar_flags(argc,argv);
	data.stack_a = stack_init(res, size);
	data.stack_b = stack_init(NULL, 0);
	write(1, "2", 2);
	start_program(&data);
	write(1, "3", 2);
	if (data.flags.has_bench == 1)
		print_bench(&data);
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}	 

