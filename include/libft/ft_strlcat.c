/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:44:32 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/03 12:49:01 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	d_len;
	unsigned int	s_len;

	s_len = ft_strlen(src);
	d_len = 0;
	while (*dst != '\0' && size > 0)
	{
		d_len++;
		dst++;
		size--;
	}
	while (*src != '\0' && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	if (size == 1 || *src == 0)
	{
		*dst = '\0';
	}
	return (d_len + s_len);
}
