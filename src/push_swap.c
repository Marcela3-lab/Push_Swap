#include "push_swap.h"

void	print_bench(t_data *data)
{
	float	d;
	char	*strategy[] = {"Simple", "Medium", "Complex", "Adaptive"};
	char	*complexity[] = {"O(1)", "On^2", "O(n*sqrt(n))", "O(nlog(n))"};
	int		sum_ops;
	
	d = data->bench.disorder * 100;
	sum_ops = data->bench.pa + data->bench.pb
		+ data->bench.sa + data->bench.sb + data->bench.ss
		+ data->bench.ra + data->bench.rb + data->bench.rr
		+ data->bench.rra + data->bench.rrb + data->bench.rrr;
	printf("[bench] disorder: %.2f%%\n", d);	
	printf("[bench] strategy: %s / %s\n", strategy[data->flags.strategy]
		, complexity[data->bench.complexity]);
	printf("[bench] total ops: %d\n", sum_ops);
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", data->bench.sa, data->bench.sb,
		data->bench.ss, data->bench.pa, data->bench.pb);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", data->bench.ra, data->bench.rb,
		data->bench.rr, data->bench.rra, data->bench.rrb, data->bench.rrr);
}

int	main(int argc, char **argv)
{
	int		*res;
	int		size;
	t_data	data;

	res = splitmain(argc, argv, &size);
	if (!res)
		return (1);
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

	
	// printf("flags.has_flags = %d\n", data.flags.has_flags);
	// printf("flags.has_bench = %d\n", data.flags.has_bench);
	// printf("flags.strategy = %d\n", data.flags.strategy);
	
	// printf("stack_a head value = %d\n", data.stack_a->head->value);
	// printf("stack_a head index = %d\n", data.stack_a->head->index);
	// printf("stack_a size = %zu\n", data.stack_a->size);

	//testes
	// printf("stack a:\nHEAD--> value > %d; position > %d: index > %d\n", a->head->value, a->head->position, a->head->index);
	// printf("TAIL --> value > %d; position > %d: index > %d\n", a->tail->value, a->tail->position, a->tail->index);
	// printf("stack a: size = %zu\nstack b: size = %zu\n", a->size, b->size);
}	
