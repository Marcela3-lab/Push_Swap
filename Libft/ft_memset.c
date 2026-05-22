/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:16:35 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/20 11:28:10 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		arr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int	main()
// {
// 	char	str[10];
// 	int		i;

// 	i = 0;

// 	ft_memset(str, 'A', 9);
// 	str[9] = '\0';

// 	printf("%s\n", str);

// 	while (i < 10)
// 	{
// 		printf("%c ", str[i]);
// 		i++;
// 	}

// 	return (0);
// }