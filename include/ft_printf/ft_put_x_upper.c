/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x_upper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:24:53 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/14 08:52:30 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hexa(unsigned int n);

int	put_x_upper(int n, int fd)
{
	int	counter;

	counter = ft_count_hexa(n);
	if (n >= 0 && n <= 15)
	{
		write(fd, &"0123456789ABCDEF"[n], 1);
	}
	else
	{
		put_x_upper(n / 16, fd);
		put_x_upper(n % 16, fd);
	}
	return (counter);
}

static int	ft_count_hexa(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
	{
		counter += 1;
	}
	while (n > 0)
	{
		n = n / 16;
		counter++;
	}
	return (counter);
}
