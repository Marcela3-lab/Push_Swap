/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotatestacks_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:21:36 by marcebar          #+#    #+#             */
/*   Updated: 2026/06/02 17:23:55 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	revrotate(t_stack *stack)
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
	if (data->flags.has_bench == 1)
		data->bench.rra += 1;
}

void	rrb(t_data *data)
{
	revrotate(data->stack_b);
	write(1, "rrb\n", 4);
	if (data->flags.has_bench == 1)
		data->bench.rrb += 1;
}

void	rrr(t_data *data)
{
	revrotate(data->stack_a);
	revrotate(data->stack_b);
	write(1, "rrr\n", 4);
	if (data->flags.has_bench == 1)
		data->bench.rrr += 1;
}

/* int main()
{
	t_stack *a = malloc(sizeof(t_stack));
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));

	node1->index = -1;
	node1->position = -1;
	node1->value = 1;
	node2->index = -1;
	node2->position = -1;
	node2->value = 2;
	node3->index = -1;
	node3->position = -1;
	node3->value = 3;
	node3->next = NULL;
	node3->prev = node2;
	node2->next = node3;
	node2->prev = node1;
	node1->next = node2;
	node1->prev = NULL;
	a -> head = node1;
	a -> tail = node3;
	a -> size = 3;

	t_stack *b = malloc(sizeof(t_stack));
	t_node *nodeb1 = malloc(sizeof(t_node));
	// t_node *nodeb2 = malloc(sizeof(t_node));
	// t_node *nodeb3 = malloc(sizeof(t_node));

	nodeb1->index = -1;
	nodeb1->position = -1;
	nodeb1->value = 1;
	// nodeb2->index = -1;
	// nodeb2->position = -1;
	// nodeb2->value = 2;
	// nodeb3->index = -1;
	// nodeb3->position = -1;
	// nodeb3->value = 3;
	// nodeb3->next = NULL;
	// nodeb3->prev = nodeb2;
	// nodeb2->next = nodeb3;
	// nodeb2->prev = nodeb1;
	nodeb1->next = NULL;
	nodeb1->prev = NULL;
	b -> head = nodeb1;
	b -> tail = nodeb1;
	b -> size = 1;

	printf("BEFORE\na->head->value: %d\na->tail->value: %d\n", a->head->value, a->tail->value);
	rra(a);
	printf("AFTER\na->head->value: %d\na->tail->value: %d\n", a->head->value, a->tail->value);
	printf("BEFORE\nb->head->value: %d\nb->tail->value: %d\n", b->head->value, b->tail->value);
	rrb(b);
	printf("AFTER\nb->head->value: %d\nb->tail->value: %d\n", b->head->value, b->tail->value);
	rrr(a, b);
	printf("AFTER\na->head->value: %d\na->tail->value: %d\n", a->head->value, a->tail->value);
	printf("AFTER\nb->head->value: %d\nb->tail->value: %d\n", b->head->value, b->tail->value);
	free(a);
	free(node1);
	free(node2);
	free(node3);
	free(b);
	free(nodeb1);
	// free(nodeb2);
	// free(nodeb3);
	return(0);
} */