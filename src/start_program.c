#include "push_swap.h"

void    start_program(t_data *data)
{
	float	disorder;

	disorder = normalize_index(data->stack_a);
	if (disorder == 0)
		return ;
	// has flags? If no, check disorder and call algorithm
				//if yes, check flag call algorithm
	//has bench? If yes -> print data in fd = 2 (stderr)
}