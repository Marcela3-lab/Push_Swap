/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushpop_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:20:17 by marcebar          #+#    #+#             */
/*   Updated: 2026/06/02 17:20:21 by marcebar         ###   ########.fr       */
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
	if (data->flags.has_bench == 1)
		data->bench.pb += 1;
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
	if (data->flags.has_bench == 1)
		data->bench.pa += 1;
}
/* int main()
{
	t_stack *a = malloc(sizeof(t_stack));
	t_stack *b = malloc(sizeof(t_stack));
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));

	node1->index = -1;
	node1->value = 1;
	node2->index = -1;
	node2->value = 2;
	node3->index = -1;
	node3->value = 3;
	node3->next = NULL;
	node3->prev = node1;
	node2->next = NULL;
	node2->prev = NULL;
	node1->next = node3;
	node1->prev = NULL;
	a -> head = node1;
	a -> tail = node3;
	a -> size = 2;
	b -> head = node2;
	b -> tail = node2;
	b -> size = 1;

	printf("BEFORE\na->head->value: %d\nsize a: %zu\n", a->head->value, a->size);
	printf("BEFORE\nb->head->value: %d\nsize b: %zu\n", b->head->value, b->size);
	pb(a, b);
	printf("AFTER\na->head->value: %d\nsize a: %zu\n", a->head->value, a->size);
	printf("AFTER\nb->head->value: %d\nsize b: %zu\n", b->head->value, b->size);
	pa(b, a);
	printf("AFTER\na->head->value: %d\nsize a: %zu\n", a->head->value, a->size);
	printf("AFTER\nb->head->value: %d\nsize b: %zu\n", b->head->value, b->size);
	free(a);
	free(b);
	free(node1);
	free(node2);
	free(node3);
	return(0);
} */