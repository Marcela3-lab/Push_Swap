#include "../push_swap.h"

t_node	*min_index_node(t_node *current)
{
	t_node	*minimum;

	minimum = NULL;
	while (current)
	{
		if (!minimum)
			minimum = current;
		else if (minimum->index > current->index)
			minimum = current;
		current = current->next;
	}
	return (minimum);
}

void	update_positions(t_stack *stack)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = stack->head;
	while (i < stack->size)
	{
		node->position = i;
		node = node->next;
		i++;
	}
}

//Simple Algorithm: Simple Min extraction O(n2)
void	simple(t_data *data)
{
	t_node	*min;

	while (data->stack_a->size != 0)
	{
		update_positions(data->stack_a);
		min = min_index_node(data->stack_a->head);
		if (min->position == 0)
			pb(data);
		else
		{
			while(min->position != 0)
			{
				update_positions(data->stack_a);
				if (min->position <= (int)data->stack_a->size / 2 && min->position != 0)	
					ra(data);
				else if (min->position >= (int)data->stack_a->size / 2 && min->position != 0)
					rra(data);
			}
			pb(data);
		}
	}
	while (data->stack_b->size != 0)
		pa(data);
	data->bench.complexity = on2;
	return ;
}
//TESTES MAIN
/* int main()
{
 	t_data	data;
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));
	t_node *node4 = malloc(sizeof(t_node));

	ft_bzero(&data, sizeof(t_data));
    data.flags.has_bench = 1;

	//init stacks
    data.stack_a = malloc(sizeof(t_stack));
    data.stack_b = malloc(sizeof(t_stack));

	//value
	node1->value = 89;
	node2->value = -8;
	node3->value = 56;	
	node4->value = 10;

	//index
	node1->index = 3;
	node2->index = 0;
	node3->index = 2;
	node4->index = 1;

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
	printf("%d->%d->%d->%d\n", node1->value, node2->value, node3->value, node4->value);
	printf("a head: %d\na tail: %d\n", data.stack_a->head->value, data.stack_a->tail->value);
	printf("size a: %zu\nsize b: %zu\n", data.stack_a->size, data.stack_b->size);
    simple(&data);
	printf("AFTER\na head: %d\na tail: %d\n", data.stack_a->head->value, data.stack_a->tail->value);
	printf("size a: %zu\nsize b: %zu\n", data.stack_a->size, data.stack_b->size);
	
	//teste de soma de operacoes no bench
    printf("sa: %d | ra: %d | rra: %d\n", data.bench.sa, data.bench.ra, data.bench.rra);
    printf("pb: %d | pa: %d\n", data.bench.pa, data.bench.pb);
	
	// t_node *min = malloc(sizeof(t_node));
	// min = min_index_node(a->head);
	// printf("%d:%d", min->value, min->position);

	// update_positions(a);
	// printf("%d->%d->%d->%d\n", node1->position, node2->position, node3->position, node4->position);
	

	//free
	free(data.stack_a);
	free(data.stack_b);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return(0);
} */