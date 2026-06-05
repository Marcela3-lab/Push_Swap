/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:54:00 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/05 14:54:01 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	pushed;
	int	total;

	total = data->stack_a->size;
	start = 0;
	end = chunk_size - 1;
	while (start < total)
	{
		pushed = 0;
		while (pushed < chunk_size && data->stack_a->size > 0)
		{
			if (data->stack_a->head->index >= start
				&& data->stack_a->head->index <= end)
			{
				pb(data);
				pushed++;
			}
			else
				ra(data);
		}
		start = end + 1;
		end += chunk_size;
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
			if (max->position < (int)data->stack_b->size / 2)
				rb(data);
			else
				rrb(data);
			update_positions(data->stack_b);
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

	chunk_size = ft_sqrt(data->stack_a->size);
	push_chunks_to_b(data, chunk_size);
	push_back_to_a(data);
	data->bench.complexity = onn;
}