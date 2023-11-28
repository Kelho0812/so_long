/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:12:26 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/12 09:25:07 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counter_recursive(long long n);

int	ft_put_int(int num, int fd)
{
	int			counter;
	long long	n;

	n = num;
	counter = ft_counter_recursive(num);
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_put_int(n / 10, fd);
		ft_put_int(n % 10, fd);
	}
	return (counter);
}

static int	ft_counter_recursive(long long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		n = n * (-1);
		counter = 1;
	}
	if (n == 0)
	{
		counter += 1;
	}
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}
