/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:53:51 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 09:42:58 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	str = s;
	i = 0;
	while (i < n)
	{
		*str++ = c;
		i++;
	}
	return ((void *)s);
}
