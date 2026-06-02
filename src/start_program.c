#include "push_swap.h"

void	run_adaptive(t_data *data)
{
	float	d;

	d = data->bench.disorder;
	if (d > 0 && d < 0.2)
	{
		write(1, "i", 2);
		simple(data);
	}
	else if (d >= 0.2 && d < 0.5)
	{
		write(1, "j", 2);
		complex(data);
	}
	else if (d >= 0.5)
	{
		write(1, "k", 2);
		complex (data);
	}
	return ;
}

void    start_program(t_data *data)
{
	write(1, "a", 2);
	float	disorder;

	if (data->stack_a->size <= 3)
	{
		write(1, "b", 2);
		sort_small(data);
		return ;
	}
	normalize_index(data->stack_a);
	write(1, "c", 2);
	disorder = compute_disorder(data->stack_a);
	write(1, "d", 2);
	data->bench.disorder = disorder;
	if (disorder == 0)
		return ;
	if (data->flags.has_flags == 1 && data->flags.strategy != start_adaptive)
	{
		if (data->flags.strategy == start_simple)
		{
			write(1, "e", 2);
			simple(data);
		}
		else if (data->flags.strategy == start_medium)
		{
			write(1, "f", 2);
			medium(data);
		}
		else if (data->flags.strategy == start_complex)
		{
			write(1, "g", 2);
			complex(data);
		}
	}
	else
	{
		write(1, "h", 2);
		run_adaptive(data);
	}
	return ;
}
