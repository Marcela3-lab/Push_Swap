#include "push_swap.h"

//index de new_node tem de ser -1 !!
static t_node *get_min_node(t_node *current)
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

int	normalize_index(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		get_min_node(a->head)->index = i;
		i++;
	}
	// verificar se esta ordenado
	// se nao, 0 (False)
	// se sim, 1 (True)
}
