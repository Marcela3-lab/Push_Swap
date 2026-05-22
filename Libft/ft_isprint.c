/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:16:09 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/20 11:27:51 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
int	main(void)
{
	char c1 = 'A';
	char c2 = '\n';
	char c3 = ' ';

	printf("%d\n", ft_isprint(c1)); // 1
	printf("%d\n", ft_isprint(c2)); // 0
	printf("%d\n", ft_isprint(c3)); // 1
}
*/