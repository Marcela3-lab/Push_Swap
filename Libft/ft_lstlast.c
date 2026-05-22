/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:40:42 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 08:57:45 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main ()
// {
// 	t_list *lst = NULL;
// 	t_list *n1 = ft_lstnew("3");
// 	t_list *n2 = ft_lstnew("2");
// 	ft_lstadd_front(&lst,n1);
// 	ft_lstadd_front(&lst,n2);
// 	printf("%s",(char *)ft_lstlast(lst)->content);
// }