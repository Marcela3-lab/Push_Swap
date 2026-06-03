#include "../push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_node	*node;
	t_node	*node_next;

	if (!stack)
		return ;
	node = (*stack)->head;
	while (node)
	{
		node_next = node->next;
		free(node);
		node = node_next;
	}
	free(*stack);
	*stack = NULL;
}

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

t_node	*create_node(int number)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = number;
	new_node->index = -1;
	new_node->position = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*stack_init(int *arraynbr, int sizearray)
{
	int	i;
	t_stack	*stack;
	t_node	*node;

	i = sizearray - 1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	if (sizearray == 0)
		return (stack);
	while(i >= 0)
	{
		node = create_node(arraynbr[i]);
		if (!node)
			return (stack_clear(&stack), NULL);
		stack_addtop(node, stack);
		i--;
	}
	return (stack);
}

