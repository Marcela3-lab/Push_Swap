#include "../push_swap.h"

t_node	*max_index_node(t_node *current)

{
	t_node	*max;

	max = NULL;
	while (current)
	{
		if (!max)
			max = current;
		else if (current->index > max->index)
			max = current;
		current = current->next;
	}
	return (max);
}

void	push_chunks_to_b(t_data *data, int chunk_size)
{
	int	start;
	int	end;

	start = 0;
	end = chunk_size - 1;

	while (data->stack_a->size > 0)
	{
		if (data->stack_a->head->index >= start
			&& data->stack_a->head->index <= end)
		{
			pb(data);

			start++;
			end++;
		}
		else
			ra(data);
	}
}

/* void	update_positions(t_stack *stack)
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
} */

void	push_back_to_a(t_data *data)
{
	t_node	*max;

	while (data->stack_b->size > 0)
	{
		update_positions(data->stack_b);

		max = max_index_node(data->stack_b->head);

		while (max->position != 0)
		{
			update_positions(data->stack_b);

			if (max->position <= (int)data->stack_b->size / 2)
				rb(data);
			else
				rrb(data);
		}
		pa(data);
	}
}

void	medium(t_data *data)
{
	int	chunk_size;

	chunk_size = 5;

	push_chunks_to_b(data, chunk_size);
	push_back_to_a(data);
}

/* int main ()
{
    
} */