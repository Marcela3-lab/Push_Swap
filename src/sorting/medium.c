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
	int	j;

	j = data->stack_a->size;
	start = 0;
	end = chunk_size - 1;
	while (j > 0)
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
		j--;
	}
}

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

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

void	medium(t_data *data)
{
	int	chunk_size;

	chunk_size = (int)ft_sqrt(data->stack_a->size);
	push_chunks_to_b(data, chunk_size);
	push_back_to_a(data);
	data->bench.complexity = onn;
}
