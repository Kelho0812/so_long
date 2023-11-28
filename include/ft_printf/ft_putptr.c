/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:10:49 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/14 08:54:50 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr_recursive_fd( long long n, int fd);
static int	ft_count_hexa( long long n);

int	ft_putptr_fd(long long n, int fd)
{
	int	counter;

	counter = 0;
	if (n == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	else
	{
		write(fd, "0x", 2);
		counter = 2 + ft_count_hexa(n);
		ft_putptr_recursive_fd(n, fd);
	}
	return (counter);
}

static void	ft_putptr_recursive_fd(long long n, int fd)
{
	if (n >= 0 && n <= 15)
	{
		write(fd, &"0123456789abcdef"[n], 1);
	}
	else
	{
		ft_putptr_recursive_fd(n / 16, fd);
		ft_putptr_recursive_fd(n % 16, fd);
	}
}

static int	ft_count_hexa(long long n)
{
	int	counter;

	counter = 0;
	while (n > 0)
	{
		n = n / 16;
		counter++;
	}
	return (counter);
}
