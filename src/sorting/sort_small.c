#include "../push_swap.h"

static void	sort_three_v2(t_data *data)
{
	t_node	*node1;
	t_node	*node2;

	node1 = data->stack_a->head;
	node2 = node1->next;
	if (node2->value > node2->next->value)
	{
		ra(data);
		sa(data);
	}
	else
	{
		if (node1->value > node2->next->value)
			ra(data);
		else
			sa(data);
	}
}

static void	sort_three(t_data *data)
{
	t_node	*node1;
	t_node	*node2;

	node1 = data->stack_a->head;
	node2 = node1->next;
	if (node1->value < node2->value)
	{
		if (node2->value < node2->next->value)
			return ;
		if (node1->value < node2->next->value)
		{
			rra(data);
			sa(data);
		}
		else
			rra(data);
	}
	else
		sort_three_v2(data);
	return ;
}

void	sort_small(t_data *data)
{
	t_node	*node1;

	node1 = data->stack_a->head;
	if (!data->stack_a || data->stack_a->size <= 1)
		return ;
	if (data->stack_a->size == 2)
	{
		if (node1->value > node1->next->value)
			sa(data);
		return ;
	}
	if (data->stack_a->size == 3)
		sort_three(data);
	data->bench.complexity = o1;
	return ;
}
