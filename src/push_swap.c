#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*res;
	int		size;
	t_data	data;

	res = splitfirst(argc, argv, &size);
	if (!res)
		return (1); // print Error aqui?
	ft_bzero(&data, sizeof(t_data));
	data.flags = verificar_flags(argc,argv);
	data.stack_a = stack_init(res, size);
	data.stack_b = stack_init(NULL, 0);
	start_program(&data);
	if (data.flags.has_bench == 1)
		print_bench(&data);
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}	 

