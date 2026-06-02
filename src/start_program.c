#include "push_swap.h"

void	run_adaptive(t_data *data)
{
	float	d;

	d = data->bench.disorder;
	if (d > 0 && d < 0.2)
		simple(data);
	else if (d >= 0.2 && d < 0.5)
		medium (data);
	else if (d >= 0.5)
		complex (data);
	return ;
}

void    start_program(t_data *data)
{
	float	disorder;

	if (data->stack_a->size <= 3)
	{
		printf("running sortsmall\n"); //remover
		sort_small(data);
		return ;
	}
	printf("before normalize\n"); //remover
	normalize_index(data->stack_a);
	printf("normalized index\n"); //remover
	disorder = compute_disorder(data->stack_a);
	printf("calculated disorder d = %.2f\n", disorder); // remover
	data->bench.disorder = disorder;
	if (disorder == 0)
		return ;
	if (data->flags.has_flags == 1 && data->flags.strategy != start_adaptive)
	{
		if (data->flags.strategy == start_simple)
		{
			printf("running simple\n"); //remover
			simple(data);
		}
		else if (data->flags.strategy == start_medium)
		{
			medium(data);
			printf("running medium\n"); //remover
		}
			
		else if (data->flags.strategy == start_complex)
			complex(data);
	}
	else
		run_adaptive(data);
	return ;
}
