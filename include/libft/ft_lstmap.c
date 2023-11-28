/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:47:15 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/10 14:24:31 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*buffer;

	if (!lst || !f || !del)
		return (NULL);
	ptr = ft_lstnew(f(lst->content));
	if (!ptr)
		return (NULL);
	buffer = ptr;
	lst = lst->next;
	while (lst != NULL)
	{
		ptr->next = ft_lstnew(f(lst->content));
		if (!ptr->next)
		{
			del(ptr->content);
			free(ptr);
			return (0);
		}
		lst = lst->next;
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (buffer);
}
