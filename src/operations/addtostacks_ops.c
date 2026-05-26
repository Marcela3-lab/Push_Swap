#include "push_swapfilipa.h"
// funcao que coloca o node no topo da stack:
void	stack_addtop(t_node *node, t_stack *stack)
{
	if (!node || !stack)
		return ;
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
		stack->size = 1;
	}
	else
	{
		stack->head->prev = node;
		node->next = stack->head;
		stack->head = node;
		stack->size += 1;
	}
}
/* int main()
{
	t_stack *a = malloc(sizeof(t_stack));
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));

	node1->index = -1;
	node1->value = 1;
	node2->index = -1;
	node2->value = 2;
	node2->next = NULL;
	node2->prev = NULL;
	node1->next = NULL;
	node1->prev = NULL;
	a -> head = node1;
	a -> size = 1;
	a->tail = node1;

	stack_addtop(node2, a);
	printf("AFTER\na->head->value: %d\nsize a: %zu\n", a->head->value, a->size);
	free(a);
	free(node1);
	free(node2);
	return(0);
} */