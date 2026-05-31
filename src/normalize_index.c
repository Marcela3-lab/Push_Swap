#include "push_swap.h"

t_node *min_value_node(t_node *current)
{
	t_node	*minimum;
		
	minimum = NULL;
	while (current)
	{
		if (current->index == -1)
		{
			if (!minimum)
				minimum = current;
			else if (minimum->value > current->value)
			{
				minimum = current;
			}
		}
		current = current->next;
	}
	return (minimum);
}

float	compute_disorder(t_stack *a)
{
	t_node	*current_i;
	t_node	*current_j;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current_i = a->head;
	while (current_i->next)
	{
		current_j = current_i->next;
		total_pairs += 1;
		if (current_i->index > current_j->index)
			mistakes += 1;
		current_i = current_i->next;
	}
	return (mistakes / total_pairs);
}	

void	normalize_index(t_stack *a)
{
	size_t	i;

	//definir o index para cada node
	i = 0;
	while (i < a->size)
	{
		min_value_node(a->head)->index = i;
		i++;
	}
	return ;
}
/* int main ()
{
	t_stack *a = malloc(sizeof(t_stack));
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));
	float n = 0;

	node1->index = -1;
	node1->value = 3;
	node2->index = -1;
	node2->value = 2;
	node3->index = -1;
	node3->value = 1;
	node3->next = NULL;
	node3->prev = node2;
	node2->next = node3;
	node2->prev = node1;
	node1->next = node2;
	node1->prev = NULL;
	a -> head = node1;
	a -> size = 3;

	printf("BEFORE\nnode1 index: %d\nnode2 index: %d\nnode3 index: %d\nsize = %zu\n", node1->index, node2->index, node3->index, a->size);
	n = normalize_index(a);
	printf("AFTER\nnode1 index: %d\nnode2 index: %d\nnode3 index: %d\ndisorder= %f\n", node1->index, node2->index, node3->index, n);
	free(a);
	free(node1);
	free(node2);
	free(node3);
	return(0);
} */

/* 	// verificar se esta ordenado - Meu
	i = 0;
	current = a->head;
	while (i < a->size)
	{
		if (current->index != i)
			return (0); 
		i++;
		current = current->next;
	}
	return (1); */