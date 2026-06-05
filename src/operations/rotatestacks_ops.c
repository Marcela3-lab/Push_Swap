/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatestacks_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:24:53 by marcebar          #+#    #+#             */
/*   Updated: 2026/06/05 12:08:31 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*top_node;

	if (!stack || stack->size <= 1)
		return ;
	top_node = stack->head;
	stack->head = top_node->next;
	stack->head->prev = NULL;
	stack->tail->next = top_node;
	top_node->prev = stack->tail;
	stack->tail = top_node;
	top_node->next = NULL;
}

void	ra(t_data *data)
{
	rotate(data->stack_a);
	write(1, "ra\n", 3);
	data->bench.ra += 1;
	data->bench.sum_ops += 1;
}

void	rb(t_data *data)
{
	rotate(data->stack_b);
	write(1, "rb\n", 3);
	data->bench.rb += 1;
	data->bench.sum_ops += 1;
}

void	rr(t_data *data)
{
	rotate(data->stack_a);
	rotate(data->stack_b);
	write(1, "rr\n", 3);
	data->bench.rr += 1;
	data->bench.sum_ops += 1;
}
