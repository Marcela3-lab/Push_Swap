/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:39:04 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 14:13:00 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_node, del);
			if (del)
				del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void *f(void *it)
// {
// 	char *copia;
// 	 char *str = (char *)it;
// 	 copia = ft_strdup(str);
//     copia[0] = 'O';
// 	return copia;
// }
// void del_content (void *content)
// {
// 	free(content);
// }
// int main()
// {
// 	t_list *lst = ft_lstnew("hi");
// 	t_list *n1 = ft_lstnew("hi");
// 	t_list *new_lst = ft_lstmap(lst, f, del_content);
// 	t_list *tmp = new_lst;
// 	ft_lstadd_back(&lst,n1);
// 	ft_lstmap(lst,f,del_content);
// 	while (tmp)
// {
//     printf("%s\n", (char *)tmp->content);
//     tmp = tmp->next;
// }
// }