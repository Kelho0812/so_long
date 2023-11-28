/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:24:51 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 10:57:21 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strrchr() function returns a pointer to the
// last occurrence of the character c in the string s.
char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	s += n;
	while (n >= 0 && *s != (char)c)
	{
		s--;
		n--;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
