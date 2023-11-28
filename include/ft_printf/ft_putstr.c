/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:27:04 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/03 13:40:07 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_printf(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_fd_printf("(null)", 1));
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
