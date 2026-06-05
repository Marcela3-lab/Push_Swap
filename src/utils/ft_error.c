/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdos-rei <fdos-rei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:23:25 by fdos-rei          #+#    #+#             */
/*   Updated: 2026/06/05 15:23:38 by fdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **res)
{
	int	i;

	i = 0;
	if (!res)
		return ;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free (res);
}

void	free_and_exit(char **res, int *numbers)
{
	if (res)
		free_split(res);
	if (numbers)
		free(numbers);
	write(2, "Error\n", 6);
	exit(1);
}
