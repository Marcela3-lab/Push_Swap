/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:24:33 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/05 15:42:14 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_disorder(float d)
{
	int	decimals;

	decimals = (int)((d - (int)d) * 100);
	write(2, "[bench] disorder: ", 18);
	ft_putnbr_fd((int)d, 2);
	write(2, ".", 2);
	ft_putnbr_fd(decimals, 2);
	write(2, "%\n", 2);
	return ;
}

static void	print_strategy(int s, int c)
{
	static char	*strategy[] = {"Simple", "Medium", "Complex", "Adaptive"};
	static char	*complexity[] = {"O(1)", "On^2", "O(n*sqrt(n))", "O(nlog(n))"};

	write(2, "[bench] strategy: ", 18);
	ft_putstr_fd((char *)strategy[s], 2);
	write(2, " / ", 4);
	ft_putstr_fd((char *)complexity[c], 2);
	write(2, "\n", 1);
	return ;
}

static void	print_sum_ops(t_bench *bench)
{
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(bench->sum_ops, 2);
	write(2, "\n", 1);
}

static void	print_ops(t_bench *bench)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr_fd(bench->sa, 2);
	write(2, " sb: ", 5);
	ft_putnbr_fd(bench->sb, 2);
	write(2, " ss: ", 5);
	ft_putnbr_fd(bench->ss, 2);
	write(2, " pa: ", 5);
	ft_putnbr_fd(bench->pa, 2);
	write(2, " pb: ", 5);
	ft_putnbr_fd(bench->pb, 2);
	write(2, "\n[bench]", 8);
	write(2, " ra: ", 5);
	ft_putnbr_fd(bench->ra, 2);
	write(2, " rb: ", 5);
	ft_putnbr_fd(bench->rb, 2);
	write(2, " rr: ", 5);
	ft_putnbr_fd(bench->rr, 2);
	write(2, " rra: ", 6);
	ft_putnbr_fd(bench->rra, 2);
	write(2, " rrb: ", 6);
	ft_putnbr_fd(bench->rrb, 2);
	write(2, " rrr: ", 6);
	ft_putnbr_fd(bench->rrr, 2);
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
	return ;
}
