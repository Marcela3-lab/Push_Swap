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
void	complex(t_data *data)
{
	int	i;
	int	n;
	int	j;
	t_node	*node;

	i = 0;
	j = data->stack_a->size - 1;
	n = count_bits(j);
	while (i < n)
	{
		j = data->stack_a->size - 1;
		node = data->stack_a->head;
		while (j >= 0)
		{
			if((node->index >> i) & 1)
				ra(data);
			else
				pb(data);
			node = data->stack_a->head;
			j--;
		}
		while (data->stack_b->size != 0)
			pa(data);
		i++;
	}
	data->bench.complexity = onlogn;
	return ;
}


/* //test count_bits
int main ()
{
	int	n = 1;
	int n1 = 10;
	int n2 = 10045851;

	printf("%u\n%u\n%u\n", count_bits(n), count_bits(n1), count_bits(n2));
	return(0);
} */