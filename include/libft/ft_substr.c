/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:29:43 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 12:30:14 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	size;

	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (!s)
	{
		return (NULL);
	}
	size = ft_strlen(s + start);
	if (size < len)
	{
		len = size;
	}
	s2 = malloc(len + 1);
	if (!s2)
	{
		return (NULL);
	}
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}
