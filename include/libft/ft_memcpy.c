/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:25:17 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/06 15:04:33 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;

	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!src && !dest)
	{
		return (dest);
	}
	while (n--)
	{
		*dst++ = *s++;
	}
	return (dest);
}
