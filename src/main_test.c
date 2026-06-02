#include "push_swap.h"


//teste count_bits(size - 1);
int main()
{
    t_data	data;
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));
	t_node *node4 = malloc(sizeof(t_node));

	printf(">>> INICIO DA MAIN\n");
	ft_bzero(&data, sizeof(t_data));
    data.flags.has_bench = 1;
	printf("[debug]defined has bench = 1\n")
    data.flags.strategy = 0;
    data.flags.has_flags = 1;


	//init stacks
    data.stack_a = malloc(sizeof(t_stack));
    data.stack_b = malloc(sizeof(t_stack));

	//value
	node1->value = 9;
	node2->value = 1;
	node3->value = 2;	
	node4->value = 10;

	//index
	node1->index = -1;
	node2->index = -1;
	node3->index = -1;
	node4->index = -1;

	//position
	node1->position = -1;
	node2->position = -1;
	node3->position = -1;
	node4->position = -1;

	//next/prev
	node4->next = NULL;
	node4->prev = node3;
	node3->next = node4;
	node3->prev = node2;
	node2->next = node3;
	node2->prev = node1;
	node1->next = node2;
	node1->prev = NULL;


	//stack head/tail/size
	data.stack_a->head = node1;
	data.stack_a->tail = node4;
	data.stack_a->size = 4;
	data.stack_b->head = NULL;
	data.stack_b->tail = NULL;
	data.stack_b->size = 0;


	//PRINTF
    printf("BEFORE:\n");
	// printf("%d->%d->%d->%d\n", node1->value, node2->value, node3->value, node4->value);
	printf("a head: %d\na tail: %d\n", data.stack_a->head->value, data.stack_a->tail->value);
	printf("size a: %zu\nsize b: %zu\n", data.stack_a->size, data.stack_b->size);
	start_program(&data);
    printf("AFTER\na head: %d\na tail: %d\n", data.stack_a->head->value, data.stack_a->tail->value);
	printf("size a: %zu\nsize b: %zu\n", data.stack_a->size, data.stack_b->size);
    
    //teste de soma de operacoes no bench
    printf("sa: %d | ra: %d | rra: %d\n", data.bench.sa, data.bench.ra, data.bench.rra);
    printf("pb: %d | pa: %d\n", data.bench.pa, data.bench.pb);
    printf("complexity: %d\n", data.bench.complexity);
    printf("strategy: %d\n", data.flags.strategy);

	

	//free
	free(data.stack_a);
	free(data.stack_b);
	free(node1);
	free(node2);
	free(node3);
	free(node4);

	return(0); 
} 