/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificar_erros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:50:16 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/07 15:38:44 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static int	num_duplicate(int *arr, int j)
{
	int	i;

	i = j - 1;
	while (i >= 0)
	{
		if (arr[i] == arr[j])
		{
			return (1);
		}
		i--;
	}
	return (0);
}

int	num_valid(char **str)
{
	int	i;
	int	j;

	j = 0;
	if (!str)
		return (0);
	while (str[j] != NULL)
	{
		i = 0;
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		if (!str[j][i])
			return (0);
		while (str[j][i])
		{
			if (!ft_isdigit(str[j][i]))
			{
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

static void	set_strategy(t_flags *flags, char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		flags->strategy = start_simple;
	else if (ft_strcmp(arg, "--medium") == 0)
		flags->strategy = start_medium;
	else if (ft_strcmp(arg, "--complex") == 0)
		flags->strategy = start_complex;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		flags->strategy = start_adaptive;
	else
		return ;
	flags->has_flags = 1;
}

t_flags	verify_flags(int argc, char **argv)
{
	int		i;
	t_flags	flags;

	i = 1;
	flags.has_flags = 0;
	flags.has_bench = 0;
	flags.strategy = start_adaptive;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			flags.has_bench = 1;
		else
			set_strategy(&flags, argv[i]);
		i++;
	}
	return (flags);
}

int	numbers_verifications(char **res, int *numbers)
{
	int			j;
	int			size;
	long long	num;
	int			index;

	index = 0;
	size = count_args(res);
	j = 0;
	while (j < size)
	{
		num = ft_atoi(res[j]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		numbers[index] = (int)num;
		if (index >= 1)
		{
			if (num_duplicate(numbers, index))
				return (1);
		}
		index++;
		j++;
	}
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	int res;
// 	int arr[] = {4, 6, 42};
// 	i = 1;
// 	// while (i < argc)
// 	// {
// 	// 	i++;
// 	// }
// 	res = num_duplicate(arr, 2);
// 	printf("%d",res);
// 	return (0);
// }