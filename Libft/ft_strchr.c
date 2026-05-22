/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:10:30 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/21 17:03:38 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

//int main()
//{
//	int i;
//	i = 0;
//	const char s[] = "abna";
//	char c = 'b';
//	char *res = ft_strchr(s,c);
//	while (res[i] != '\0')
//	{
//	printf("Resultado %c\n", res[i]);
//		i++;
//	}
//}