/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 11:07:17 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/29 16:13:44 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest1;
	const char	*src1;

	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}

// int main()
// {
// 	char a[] = "ola";
// 	char b[4];

// 	ft_memcpy(b, a, 4);

// 	printf("%s\n", b);
// }