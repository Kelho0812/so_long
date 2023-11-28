/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:19:54 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 12:31:34 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr() function returns a pointer
// to the first occurrence of the character c in the string s.
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
