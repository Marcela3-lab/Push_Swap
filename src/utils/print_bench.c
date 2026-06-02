#include "../push_swap.h"

static void print_disorder(float    d)
{
    int			decimals;
    
    decimals = (int)((d - (int)d)*100);
    write(2, "[bench] disorder:",17);
	ft_putnbr_fd((int)d, 2);
	write(2, ".", 2);
	ft_putnbr_fd(decimals, 2);
	write(2, "%\n", 2);
    return ;
}

void	print_bench(t_data *data)
{
	float		d;
	static char	*strategy[] = {"Simple", "Medium", "Complex", "Adaptive"};
	static char	*complexity[] = {"O(1)", "On^2", "O(n*sqrt(n))", "O(nlog(n))"};
	int			sum_ops;
	
	d = data->bench.disorder * 100;
	sum_ops = data->bench.pa + data->bench.pb
		+ data->bench.sa + data->bench.sb + data->bench.ss
		+ data->bench.ra + data->bench.rb + data->bench.rr
		+ data->bench.rra + data->bench.rrb + data->bench.rrr;
    print_disorder (d);
	write(2, "[bench] strategy:",17);
	ft_putstr_fd(strategy[data->flags.strategy], 2);
	write(2, " / \n", 5);
	ft_putstr_fd(complexity[data->bench.complexity], 2);
	printf("[bench] total ops: %d\n", sum_ops);
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", data->bench.sa, data->bench.sb,
		data->bench.ss, data->bench.pa, data->bench.pb);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", data->bench.ra, data->bench.rb,
		data->bench.rr, data->bench.rra, data->bench.rrb, data->bench.rrr);
}