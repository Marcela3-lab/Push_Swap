/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:10:59 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/20 11:28:45 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

//#include <stdio.h>

//int	main(void)
//{
//	const char	s[] = "abna";
//	char		c = 'b';
//	char		*res;
//	char		*start;

//	res = ft_strrchr(s, c);

//	start = (char *)s;

//	while (res >= start)
//	{
//		printf("Resultado %c\n", *res);
//		res--;
//	}
//}