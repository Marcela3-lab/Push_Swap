/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcebar <marcebar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 09:27:55 by marcebar          #+#    #+#             */
/*   Updated: 2026/04/26 09:22:59 by marcebar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int main ()
// {
// 	t_list *lst = NULL;
// 	t_list *n1 = ft_lstnew("a");
// 	t_list *n2 = ft_lstnew("b");

// 	ft_lstadd_front(&lst,n1);
// 	ft_lstadd_front(&lst,n2);

// 	printf("%d",ft_lstsize (lst));
// }