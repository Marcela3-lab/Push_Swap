/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:26:32 by marcebar          #+#    #+#             */
/*   Updated: 2026/06/05 12:06:11 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack || stack->size < 2)
		return ;
	node1 = stack->head;
	node2 = node1->next;
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = NULL;
	node2->next = node1;
	node1->prev = node2;
	stack->head = node2;
	if (stack->size == 2)
		stack->tail = node1;
}

void	sa(t_data *data)
{
	swap(data->stack_a);
	write(1, "sa\n", 3);
	data->bench.sa += 1;
}

void	sb(t_data	*data)
{
	swap(data->stack_b);
	write(1, "sb\n", 3);
	data->bench.sb += 1;
}

void	ss(t_data *data)
{
	swap(data->stack_a);
	swap(data->stack_b);
	write(1, "ss\n", 3);
	data->bench.ss += 1;
}
