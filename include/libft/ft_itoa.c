/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:25:42 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/10 14:33:29 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_digits(long n);

char	*ft_itoa(int n)
{
	int		length;
	char	*result;
	long	nbr;

	nbr = n;
	length = ft_digits(n);
	if (nbr < 0)
		length = length + 1;
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * -1;
	}
	result[length] = '\0';
	while (nbr >= 10)
	{
		length--;
		result[length] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	result[length - 1] = nbr + 48;
	return (result);
}

static long	ft_digits(long n)
{
	long	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
