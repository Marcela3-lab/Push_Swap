#include "../push_swap.h"

// funcao que retira o node do topo da stack:
void	pop_stack(t_node *node, t_stack *stack)
{
	if (!stack)
		return ;
	else if (stack->size > 1)
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->size -= 1;
	}
	else
	{
		stack->head = NULL;
		stack->size = 0;
		stack->tail = NULL;
	}
	node->next = NULL;
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node1;

	node1 = NULL;
	if (!a || !b)
		return ;
	else
		node1 = a->head;
	pop_stack(node1, a);
	stack_addtop(node1, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node1;

	node1 = NULL;
	if (!a || !b)
		return ;
	else
		node1 = b->head;
	pop_stack(node1, b);
	stack_addtop(node1, a);
	write(1, "pa\n", 3);
}
/* int main()
{
	t_stack *a = malloc(sizeof(t_stack));
	t_stack *b = malloc(sizeof(t_stack));
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));

	node1->index = -1;
	node1->value = 1;
	node2->index = -1;
	node2->value = 2;
	node3->index = -1;
	node3->value = 3;
	node3->next = NULL;
	node3->prev = node1;
	node2->next = NULL;
	node2->prev = NULL;
	node1->next = node3;
	node1->prev = NULL;
	a -> head = node1;
	a -> tail = node3;
	a -> size = 2;
	b -> head = node2;
	b -> tail = node2;
	b -> size = 1;

	printf("BEFORE\na->head->value: %d\nsize a: %zu\n", a->head->value, a->size);
	printf("BEFORE\nb->head->value: %d\nsize b: %zu\n", b->head->value, b->size);
	pb(a, b);
	printf("AFTER\na->head->value: %d\nsize a: %zu\n", a->head->value, a->size);
	printf("AFTER\nb->head->value: %d\nsize b: %zu\n", b->head->value, b->size);
	pa(b, a);
	printf("AFTER\na->head->value: %d\nsize a: %zu\n", a->head->value, a->size);
	printf("AFTER\nb->head->value: %d\nsize b: %zu\n", b->head->value, b->size);
	free(a);
	free(b);
	free(node1);
	free(node2);
	free(node3);
	return(0);
} */