/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:18:15 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/20 11:27:26 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
}

// int main()
// {
//	int str[3];
//	str[0] = 1;
//	str[1] = 2;
//	str[2] = 3;
//printf("antes: %d%d%d\n", str[0],str[1],str[2]);
//	ft_bzero(str, sizeof(str));
//printf("depois: %d%d%d\n", str[0],str[1],str[2]);
//	return (0);
// }