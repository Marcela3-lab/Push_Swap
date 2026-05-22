/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:11:16 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 14:10:08 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
#include <stdlib.h>

static int	quant(int n)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	if (num <= 0)
		i = 1;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	long	num;
	int		quantidade;

	num = n;
	quantidade = quant(n);
	array = malloc(quantidade + 1);
	if (!array)
		return (NULL);
	array[quantidade] = '\0';
	if (num < 0)
	{
		array[0] = '-';
		num = -num;
	}
	if (num == 0)
		array[0] = '0';
	while (num > 0)
	{
		quantidade--;
		array[quantidade] = (num % 10) + '0';
		num /= 10;
	}
	return (array);
}

// int main()
// {
// 	int n = -4;
// 	char *res;
// 	res = ft_itoa(-120);
// 	printf("%s", res);
// }