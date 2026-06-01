/* #include "push_swap.h"


int	main(int argc, char **argv)
{
	int		*res;
	int		size;
	t_data	data;

	res = splitmain(argc, argv, &size);
	//printf("%d ",res[1]);
	//printf("%d ",res[0]);
	if (!res)
		return (1);
	printf(" %d ",size);
	ft_bzero(&data, sizeof(t_data));
	data.flags = verificar_flags(argc,argv);
	data.stack_a = stack_init(res, size);
	data.stack_b = stack_init(NULL, 0);
	start_program(&data);
	
	
	//testes
	// printf("stack a:\nHEAD--> value > %d; position > %d: index > %d\n", a->head->value, a->head->position, a->head->index);
	// printf("TAIL --> value > %d; position > %d: index > %d\n", a->tail->value, a->tail->position, a->tail->index);
	// printf("stack a: size = %zu\nstack b: size = %zu\n", a->size, b->size);
} */	
