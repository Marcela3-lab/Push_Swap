/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:44:20 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/07 17:35:01 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*nbr;
	int		size;
	t_data	data;

	nbr = splitfirst(argc, argv, &size);
	if (!nbr)
		free_and_exit(NULL, NULL);
	ft_bzero(&data, sizeof(t_data));
	data.flags = verify_flags(argc, argv);
	data.stack_a = stack_init(nbr, size);
	if (!data.stack_a)
		free_and_exit(NULL, nbr);
	data.stack_b = stack_init(NULL, 0);
	if (!data.stack_b)
	{
		stack_clear(&data.stack_a);
		free_and_exit(NULL, nbr);
	}
	free(nbr);
	if (size > 0)
		start_program(&data);
	if (data.flags.has_bench == 1 && data.stack_a->size > 0)
		print_bench(&data);
	return (stack_clear(&data.stack_a), stack_clear(&data.stack_b), 0);
}
