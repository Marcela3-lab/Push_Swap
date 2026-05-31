#include "../push_swap.h"

t_node	*min_index_node(t_node *current)
{
	t_node *minimum;

	minimum = NULL;
	while (current)
	{
		if (!minimum)
			minimum = current;
		else if (minimum->index > current->index)
			minimum = current;
		current = current->next;	
	}
	return(minimum);
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
			pb(&data);
		else
		{
			while(min->position != 0)
			{
				update_positions(data->stack_a);
				if (min->position <= (int)data->stack_a->size / 2 && min->position != 0)	
					ra(data->stack_a);
				else if (min->position >= (int)data->stack_a->size / 2 && min->position != 0)
					rra(data->stack_a);
			}
			pb(&data);
		}
	}
	while (data->stack_b->size != 0)
		pa(&data);
}
//TESTES MAIN
/*int main()
{
	t_stack *a = malloc(sizeof(t_stack));
	t_stack *b = malloc(sizeof(t_stack));
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));
	t_node *node4 = malloc(sizeof(t_node));


	//value
	node1->value = 21;
	node2->value = 789;
	node3->value = 3;	
	node4->value = 10;

	//index
	node1->index = 2;
	node2->index = 3;
	node3->index = 0;
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
	a -> head = node1;
	a -> tail = node4;
	a -> size = 4;
	b -> head = NULL;
	b -> tail = NULL;
	b -> size = 0;

	//PRINTF
	printf("BEFORE\n%d->%d->%d->%d\n", node1->value, node2->value, node3->value, node4->value);
	printf("a head: %d\na tail: %d\n", a->head->value, a->tail->value);
	printf("size a: %zu\nsize b: %zu\n", a->size, b->size);
    simple(a, b);
	printf("AFTER\na head: %d\na tail: %d\n", a->head->value, a->tail->value);
	printf("size a: %zu\nsize b: %zu\n", a->size, b->size);
	// t_node *min = malloc(sizeof(t_node));
	// min = min_index_node(a->head);
	// printf("%d:%d", min->value, min->position);

	// update_positions(a);
	// printf("%d->%d->%d->%d\n", node1->position, node2->position, node3->position, node4->position);
	

	//free
	free(a);
	free(b);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return(0);
}*/