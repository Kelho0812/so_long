/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:12:54 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 12:31:21 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  strdup() function returns a pointer to a new string which is a du‐
// plicate of the string s.  Memory for the new string  is  obtained  with
// malloc(3), and can be freed with free(3).
char	*ft_strdup(const char *s)
{
	char	*s_copy;
	int		i;

	s_copy = malloc(ft_strlen(s) + 1);
	i = 0;
	if (!s_copy)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		s_copy[i] = s[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
