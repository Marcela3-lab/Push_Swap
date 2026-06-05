/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotatestacks_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:21:36 by marcebar          #+#    #+#             */
/*   Updated: 2026/06/05 12:06:31 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	revrotate(t_stack *stack)
{
	t_node	*tail_node;

	if (!stack || stack->size <= 1)
		return ;
	tail_node = stack->tail;
	stack->tail = tail_node->prev;
	stack->tail->next = NULL;
	stack->head->prev = tail_node;
	tail_node->next = stack->head;
	stack->head = tail_node;
	tail_node->prev = NULL;
}

void	rra(t_data *data)
{
	revrotate(data->stack_a);
	write(1, "rra\n", 4);
	data->bench.rra += 1;
}

void	rrb(t_data *data)
{
	revrotate(data->stack_b);
	write(1, "rrb\n", 4);
	data->bench.rrb += 1;
}

void	rrr(t_data *data)
{
	revrotate(data->stack_a);
	revrotate(data->stack_b);
	write(1, "rrr\n", 4);
	data->bench.rrr += 1;
}
