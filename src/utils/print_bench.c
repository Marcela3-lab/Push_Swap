#include "../push_swap.h"

static void print_disorder(float    d)
{
    int	decimals;
    
    decimals = (int)((d - (int)d)*100);
    write(2, "[bench] disorder: ",18);
	ft_putnbr_fd((int)d, 2);
	write(2, ".", 2);
	ft_putnbr_fd(decimals, 2);
	write(2, "%\n", 2);
    return ;
}

static void print_strategy(int  s, int c)
{
    static char	*strategy[] = {"Simple", "Medium", "Complex", "Adaptive"};
	static char	*complexity[] = {"O(1)", "On^2", "O(n*sqrt(n))", "O(nlog(n))"};

    write(2, "[bench] strategy: ",18);
	ft_putstr_fd((char *)strategy[s], 2);
	write(2, " / ", 4);
	ft_putstr_fd((char *)complexity[c], 2);
	write(2, "\n", 1);
    return ;

}

static void print_sum_ops(t_bench *bench)
{
    int			sum_ops;

    sum_ops = bench->pa + bench->pb
		+ bench->sa + bench->sb + bench->ss
		+ bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr;
    write(2, "[bench] total_ops: ",19);
	ft_putnbr_fd((int)sum_ops, 2);
	write(2, "\n", 1);
}
static void print_ops(t_bench *bench)
{
    const char	*ops1[] = {" sa: ", " sb: ", " ss: ", " pa: ", " pb: "};
    int     	*values1[] = {&bench->sa, &bench->sb, &bench->ss, &bench->pa, &bench->pb};
	const char	*ops2[] = {" ra: ", " rb: ", " rr: ", " rra: ", " rrb: ", " rrr: "};
    int     	*values2[] = {&bench->ra, &bench->rb, &bench->rr, &bench->rra, &bench->rrb, &bench->rrr};
	int			i;

	i = 0;
	write(2, "[bench]", 7);
	while (i < 5)
	{
		ft_putstr_fd((char *)ops1[i], 2);
		ft_putnbr_fd(*values1[i], 2);
		i++;
	}
	write(2, "\n[bench]", 8);
	i = 0;
	while (i < 6)
	{
		ft_putstr_fd((char *)ops2[i], 2);
		ft_putnbr_fd(*values2[i], 2);
		i++;
	}
	write(2, "\n", 1);
}

void	print_bench(t_data *data)
{
	float		d;
	
	d = data->bench.disorder * 100;
    print_disorder(d);
    print_strategy(data->flags.strategy, data->bench.complexity);
    print_sum_ops(&data->bench);
	print_ops(&data->bench);
}
