/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:38:50 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 14:34:07 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*no1;

	no1 = (t_list *) malloc(sizeof(t_list));
	if (!no1)
		return (NULL);
	no1 -> content = content;
	no1 -> next = NULL;
	return (no1);
}

// int main()
// {
// 	int content = 12;
// 	int content2 = 20;
// 	t_list *node1 = ft_lstnew(content);
// 	t_list *node2 = ft_lstnew(content2);
// 	node1->next = node2;
// 	printf("%d", node1->next->content);
// }