/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:44:20 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/05 15:44:21 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*res;
	int		size;
	t_data	data;

	res = splitfirst(argc, argv, &size);
	if (!res)
		free_and_exit(NULL, NULL);
	ft_bzero(&data, sizeof(t_data));
	data.flags = verificar_flags(argc, argv);

	data.stack_a = stack_init(res, size);
	
	if (!data.stack_a)
		free_and_exit(NULL, res);
	data.stack_b = stack_init(NULL, 0);
	if (!data.stack_b)
	{
		stack_clear(&data.stack_a);
		free_and_exit(NULL, res);
	}
	free(res);
	start_program(&data);
	if (data.flags.has_bench == 1)
		print_bench(&data);
	stack_clear(&data.stack_a);
	stack_clear(&data.stack_b);
	return (0);
}
