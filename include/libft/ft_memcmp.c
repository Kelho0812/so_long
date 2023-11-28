/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:16:21 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/06 14:52:17 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*string1;
	unsigned const char	*string2;

	string1 = s1;
	string2 = s2;
	i = 0;
	while (n)
	{
		if (string1[i] != string2[i])
		{
			return (string1[i] - string2[i]);
		}
		i++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("\n%d\n", ft_memcmp("abc", "abc", 7));
// 	printf("\n%d",memcmp("abc", "abc", 7));
// }