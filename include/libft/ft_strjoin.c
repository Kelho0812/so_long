/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:59:10 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 12:35:15 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a new string,
// which is the result of the concatenation of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		n;

	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		new_str[n] = s1[i];
		i++;
		n++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_str[n] = s2[i];
		i++;
		n++;
	}
	new_str[n] = '\0';
	return (new_str);
}
