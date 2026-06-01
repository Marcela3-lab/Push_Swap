#include "../push_swap.h"

//funcao que faz clear das double lists (stack e nodes)
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

//inicializa node com inteiro
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

//inicializa a stack e coloca os numeros do array de ints passado pela main
//para stack b, inicializar com stack_init(NULL, 0);
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

// int main()
// {
// 	t_stack *a;
// 	t_node	*node1 = malloc(sizeof(t_node));

// 	node1->index = -1;
// 	node1->value = 1;
// 	node1->next = NULL;
// 	node1->prev = NULL;
// 	a = stack_init(NULL, 0);
// 	printf("%zu\n", a->size);
// 	stack_addtop(node1, a);
// 	printf("%d %zu\n", a->head->value, a->size);
// 	stack_clear(&a);
// 	if (!a)
// 		printf("a cleared sucessfully\n");
// 	// free(a);
// 	// free(node1);
// 	return (0);
// }
