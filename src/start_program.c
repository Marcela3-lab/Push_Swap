#include "push_swap.h"

void    start_program(t_data *data)
{
	float	disorder;

	if (data->stack_a->size <= 3)
	{
		sort_small(data->stack_a);
		return ;
	}
	normalize_index(data->stack_a);
	disorder = compute_disorder(data->stack_a);
	data->bench.disorder = disorder;
	if (disorder == 0)
		return ; // se disorder for 0 e tiver flag bench, imprime alguma coisa??
	// has flags? If no, call algorithm according to disorder value
				//if yes, check flag call algorithm
	if (data->flags.has_bench == 1)
	{
		// print data in fd = 2 (stderr)
	}
}