/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:51:38 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/05 14:46:06 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static unsigned int	count_bits(int n)
{
	unsigned int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 2;
		i++;
	}
	return (i);
}

static void	complex_ops(t_data *data, int i)
{
	int		j;
	t_node	*node;

	j = data->stack_a->size - 1;
	node = data->stack_a->head;
	while (j >= 0)
	{
		if ((node->index >> i) & 1)
			ra(data);
		else
			pb(data);
		node = data->stack_a->head;
		j--;
	}
	return ;
}

void	complex(t_data *data)
{
	int		i;
	int		n;

	i = 0;
	n = count_bits(data->stack_a->size - 1);
	while (i < n)
	{
		complex_ops(data, i);
		while (data->stack_b->size != 0)
			pa(data);
		i++;
	}
	data->bench.complexity = onlogn;
	return ;
}
