/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:14:45 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 08:54:08 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

// int main(void)
// {
// 	t_list *lst = NULL;
// 	t_list *n1;
// 	t_list *n2;
// 	t_list *n3;
// 	t_list *tmp;
// 	n1 = ft_lstnew("2");
// 	n2 = ft_lstnew("3");
// 	n3 = ft_lstnew("4");
// 	ft_lstadd_back(&lst, n1);
// 	ft_lstadd_back(&lst, n2);
// 	ft_lstadd_back(&lst, n3);
// 	tmp = lst;
// 	while (tmp)
// 	{
// 		printf("%s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return 0;
// }