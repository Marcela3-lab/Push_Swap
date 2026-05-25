/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:08:48 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/20 11:28:00 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (i < n && s11[i] == s22[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s11[i] - (unsigned char)s22[i]);
}

//#include <stdio.h>
//int main()
//{
//	char *s1;
//	char *s2;
//	s1 = "bom";
//	s2 = "dia";
//	int res;
//	res = ft_memcmp(s1,s2,2);
//	printf("%d",res);
//}
