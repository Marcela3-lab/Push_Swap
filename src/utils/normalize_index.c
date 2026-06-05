/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:24:00 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/05 15:24:20 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*min_value_node(t_node *current)
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

float	compute_disorder(t_stack *a)
{
	t_node	*current_i;
	t_node	*current_j;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current_i = a->head;
	while (current_i->next)
	{
		current_j = current_i->next;
		total_pairs += 1;
		if (current_i->index > current_j->index)
			mistakes += 1;
		current_i = current_i->next;
	}
	return (mistakes / total_pairs);
}

void	normalize_index(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		min_value_node(a->head)->index = i;
		i++;
	}
	return ;
}
