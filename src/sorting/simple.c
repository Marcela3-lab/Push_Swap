/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:54:18 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/05 15:22:20 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*min_index_node(t_node *current)
{
	t_node	*minimum;

	minimum = NULL;
	while (current)
	{
		if (!minimum)
			minimum = current;
		else if (minimum->index > current->index)
			minimum = current;
		current = current->next;
	}
	return (minimum);
}

void	update_positions(t_stack *stack)
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

static void	rotate_min(t_data *data, t_node *min)
{
	if (min->position <= (int)data->stack_a->size / 2
		&& min->position != 0)
		ra(data);
	else if (min->position >= (int)data->stack_a->size / 2
		&& min->position != 0)
		rra(data);
	return ;
}

void	simple(t_data *data)
{
	t_node	*min;

	while (data->stack_a->size != 0)
	{
		update_positions(data->stack_a);
		min = min_index_node(data->stack_a->head);
		if (min->position == 0)
			pb(data);
		else
		{
			while (min->position != 0)
			{
				update_positions(data->stack_a);
				rotate_min (data, min);
			}
			pb(data);
		}
	}
	while (data->stack_b->size != 0)
		pa(data);
	data->bench.complexity = on2;
	return ;
}
