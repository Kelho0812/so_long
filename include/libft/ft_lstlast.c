/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:50:12 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/10 10:59:16 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	if (lst == NULL)
	{
		return (0);
	}
	while ((ptr->next) != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
