/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:39:18 by marcebar          #+#    #+#             */
/*   Updated: 2026/05/27 10:49:59 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**free_malloc(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**fill_split(char **res, char const *s, char c)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			res[k] = ft_substr(s, start, i - start);
			if (!res[k])
				return (free_malloc(res));
			k++;
		}
	}
	res[k] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (fill_split(res, s, c));
}

// int main()
// {
//     int i = 0;
//     char *s = "ola bom dia k";
//     char c = ' ';
//     char **res;
//     res = ft_split(s, c);
//     if (!res)
//         return 1;
//     while (res[i] != NULL)
//     {
//         printf("%s\n", res[i]);
//         i++;
//     }
// 	while(i--)
// 		free(res[i]);
// 	free(res);
//     return 0;
// }