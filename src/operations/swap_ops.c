/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:26:32 by marcebar          #+#    #+#             */
/*   Updated: 2026/06/02 17:27:23 by marcebar         ###   ########.fr       */
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
	if (data->flags.has_bench == 1)
		data->bench.sa += 1;
}

void	sb(t_data	*data)
{
	swap(data->stack_b);
	write(1, "sb\n", 3);
	if (data->flags.has_bench == 1)
		data->bench.sb += 1;
}

void	ss(t_data *data)
{
	swap(data->stack_a);
	swap(data->stack_b);
	write(1, "ss\n", 3);
	if (data->flags.has_bench == 1)
		data->bench.ss += 1;
}
//TESTES MAIN
/*int main()
{
	t_stack *a = malloc(sizeof(t_stack));
	// t_stack *b = malloc(sizeof(t_stack));
	t_node *node1 = malloc(sizeof(t_node));
	// t_node *node2 = malloc(sizeof(t_node));
	// t_node *node3 = malloc(sizeof(t_node));
	// t_node *nodeb1 = malloc(sizeof(t_node));
	// t_node *nodeb2 = malloc(sizeof(t_node));
	// t_node *nodeb3 = malloc(sizeof(t_node));

	node1->index = -1;
	node1->value = 1;
	// node2->index = -1;
	// node2->value = 2;
	// node3->index = -1;
	// node3->value = 3;
	// node3->next = NULL;
	// node3->prev = node2;
	// node2->next = node3;
	// node2->prev = node1;
	node1->next = NULL;
	node1->prev = NULL;
	a -> head = node1;
	a -> tail = node1;
	a -> size = 1;


	// nodeb1->index = -1;
	// nodeb1->value = 1;
	// nodeb2->index = -1;
	// nodeb2->value = 2;
	// nodeb3->index = -1;
	// nodeb3->value = 3;
	// nodeb3->next = NULL;
	// nodeb3->prev = nodeb2;
	// nodeb2->next = nodeb3;
	// nodeb2->prev = nodeb1;
	// nodeb1->next = nodeb2;
	// nodeb1->prev = NULL;
	// b->head = nodeb1;
	// b->tail = nodeb3;
	// b->size = 3;

	printf("BEFORE\n%d->%d->%d\nsize = %zu\n", a->head->value, a->head->next->value, a->tail->value, a->size);
	// printf("BEFORE\n%d->%d->%d\nsize = %zu\n", b->head->value, b->head->next->value, b->tail->value, b->size);
	// sb(b);
	sa(a);
	printf("AFTER\n%d->%d->%d\nsize = %zu\n", a->head->value, a->head->next->value, a->tail->value, a->size);
	// printf("AFTER\n%d->%d->%d\nsize = %zu\n", b->head->value, b->head->next->value, b->tail->value, b->size);
	// ss(a, b);
	printf("AFTER\n%d->%d->%d\nsize = %zu\n", a->head->value, a->head->next->value, a->tail->value, a->size);
	// printf("AFTER\n%d->%d->%d\nsize = %zu\n", b->head->value, b->head->next->value, b->tail->value, b->size);
	free(a);
	// free(b);
	free(node1);
	// free(node2);
	// free(node3);
	// free(nodeb1);
	// free(nodeb2);
	// free(nodeb3);
	return(0);
}*/