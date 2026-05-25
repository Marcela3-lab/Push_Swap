/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:26:08 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 13:15:28 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*s3;
	int		j;

	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc((len1 + len2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

// int main()
// {
// 	char *s1 = "bom";
// 	char *s2 = "dia";	
// 	char *res;
// 	res = ft_strjoin(s1, s2);
// 	printf("%s\n", res);
// 	free(res);
// }