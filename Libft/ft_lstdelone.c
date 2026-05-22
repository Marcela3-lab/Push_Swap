/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:21:25 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 08:56:39 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void del_content (void *content)
// {
// 	free(content);
// }
// int main ()
// {
// 	t_list *lst = ft_lstnew(ft_strdup("olá"));
// 	t_list *n2 = ft_lstnew(ft_strdup("mundo"));
// 	ft_lstadd_back(&lst, n2);
// 	printf("%s\n", (char *)lst->content);
// 	ft_lstdelone(lst, del_content);
// }