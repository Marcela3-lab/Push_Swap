/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:15:50 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/27 16:39:56 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main ()
// {
// 	t_list	*lst = NULL;
// 	char * text = "a";
// 	t_list *new = ft_lstnew(ft_strdup(text));
// 	ft_lstadd_front(&lst, new);
// 	printf("%s\n", (char *)lst->content);
// }