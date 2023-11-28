/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:58:16 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/10 10:10:14 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	ptr = lst;
	count = 0;
	if (lst == NULL)
	{
		return (0);
	}
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
