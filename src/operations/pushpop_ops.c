/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushpop_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:20:17 by marcebar          #+#    #+#             */
/*   Updated: 2026/06/07 17:03:55 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pop_stack(t_node *node, t_stack *stack)
{
	if (!stack)
		return ;
	else if (stack->size > 1)
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		stack->size -= 1;
	}
	else
	{
		stack->head = NULL;
		stack->size = 0;
		stack->tail = NULL;
	}
	node->next = NULL;
}

void	pb(t_data *data)
{
	t_node	*node1;

	node1 = NULL;
	if (!data->stack_a || !data->stack_b)
		return ;
	else
		node1 = data->stack_a->head;
	pop_stack(node1, data->stack_a);
	stack_addtop(node1, data->stack_b);
	write(1, "pb\n", 3);
	data->bench.pb += 1;
	data->bench.sum_ops += 1;
}

void	pa(t_data *data)
{
	t_node	*node1;

	node1 = NULL;
	if (!data->stack_a || !data->stack_b)
		return ;
	else
		node1 = data->stack_b->head;
	pop_stack(node1, data->stack_b);
	stack_addtop(node1, data->stack_a);
	write(1, "pa\n", 3);
	data->bench.pa += 1;
	data->bench.sum_ops += 1;
}
