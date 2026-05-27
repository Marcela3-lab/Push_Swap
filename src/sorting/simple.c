#include "push_swapfilipa.h"

static void	update_positions(t_stack *stack)
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

//Simple Algorithm: Simple Min/Max extraction
void	simple(t_stack *a, t_stack *b)
{
	t_node	*minimum;

	while ()
	{
		update_positions(a);
		minimum = get_min_node(a->head); //devo criar outra funcao que procura o min consoante o index? afeta performance?
		if (minimum->position == 0)
		{
			pb(a, b);
			write(1, "pb\n", 3);
		}
		else if // < size / 2
		else if // > size / 2
	}
}