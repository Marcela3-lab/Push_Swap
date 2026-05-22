/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:03:31 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/20 11:28:18 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*array;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	array = malloc(sizeof(char) * (i + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

//int main ()
//{
//	char *a;
//	char *res;
//	a = "dia";
//	res = ft_strdup(a);
//	printf("%s", res);
//}