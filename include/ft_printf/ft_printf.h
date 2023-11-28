/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:14:22 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/14 08:53:46 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_printf(const char *chars, ...);
int	ft_putstr_fd_printf(char *s, int fd);
int	ft_putchar_fd_printf(char c, int fd);
int	ft_putptr_fd(long long n, int fd);
int	put_x_lower(int n, int fd);
int	put_x_upper( int n, int fd);
int	ft_put_unsigned_int(int num, int fd);
int	ft_put_int(int num, int fd);

#endif