/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:06:56 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 08:51:13 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
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
// 	ft_lstclear(&lst, del_content);
// }