/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:30:50 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 12:33:37 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	i = 0;
	j = 0;
	s = (char *)str;
	if (to_find[i] == 0)
	{
		return (s);
	}
	while (s[i] != '\0' && n)
	{
		while (s[i + j] == to_find[j] && (i + j) < n)
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&s[i]);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
