/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:15:58 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/20 11:27:30 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*array;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ptr = (unsigned char *)array;
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (array);
}

// int main ()
// {
//	int *res;
//	res = ft_calloc(3,sizeof(int));
//	printf("%d",*res);

//	free(res);
// }