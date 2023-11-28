/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:42:19 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/03 13:39:57 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	another_function(va_list args, char c);

int	ft_printf(const char *chars, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, chars);
	i = 0;
	count = 0;
	while (chars[i] != '\0')
	{
		if (chars[i] == '%')
		{
			count += another_function(args, chars[++i]);
		}
		else
		{
			count += ft_putchar_fd_printf(chars[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	another_function(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd_printf(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd_printf(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putptr_fd(va_arg(args, unsigned long long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_put_int(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_put_unsigned_int(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (put_x_lower(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (put_x_upper(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar_fd_printf('%', 1));
	else
		return (0);
}
