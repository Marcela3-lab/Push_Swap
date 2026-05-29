#include "push_swap.h"


int	main(int argc, char **argv)
{
	int		*res;
	int		size;
	t_stack	*a;
	t_stack	*b;
	t_flags	*flags;

	res = splitmain(argc, argv, &size);
	if (!res)
		return (1);
	a = stack_init(res, size);
	b = stack_init(NULL, 0);
	start_program(a, b, flags);
	//testes
	printf("stack a:\nHEAD--> value > %d; position > %d: index > %d\n", a->head->value, a->head->position, a->head->index);
	printf("TAIL --> value > %d; position > %d: index > %d\n", a->tail->value, a->tail->position, a->tail->index);
	printf("stack a: size = %zu\nstack b: size = %zu\n", a->size, b->size);
}	
