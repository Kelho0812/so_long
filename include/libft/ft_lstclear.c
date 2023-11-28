/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:18:32 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/10 12:36:10 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	while ((*lst) != NULL)
	{
		del((*lst)->content);
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
}
