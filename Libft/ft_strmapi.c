/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:52:41 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/21 18:12:02 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*array;

	if (!s || !f)
		return (NULL);
	array = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!array)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}

// char	func_f(unsigned int i, char c)
// {
// 	return (c + i);
// }
// int main()
// {
// 	char *s = "ola";
// 	char * res;
// 	res = ft_strmapi(s, func_f);
// }