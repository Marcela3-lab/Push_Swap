/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:00:19 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 09:14:25 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void f(void *it)
// {
// 	 char *str = (char *)it;
//     str[0] = 'O';
// }
// int main ()
// {
// 	t_list *lst = ft_lstnew(ft_strdup("olá"));
// 	t_list *n2 = ft_lstnew(ft_strdup("mundo"));
// 	ft_lstadd_back(&lst, n2);
// 	printf("%s\n", (char *)lst->content);
// 	ft_lstiter(n2, f);
// 	printf("%s\n", (char *)n2->content);
// 	free(lst->content);
//     free(n2->content);
//     free(lst);
//     free(n2);
// }