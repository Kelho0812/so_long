/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:00:49 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/04 15:35:40 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	simplefree(void *pnt)
{
	if (!pnt)
		return ;
	free(pnt);
}

void	free_pnts(void **pnts)
{
	int	i;

	if (!pnts)
		return ;
	i = -1;
	while (pnts[++i])
		free(pnts[i]);
	free(pnts);
}

void	free_ppnts(void ***ppnts)
{
	int	i;

	if (!ppnts)
		return ;
	i = -1;
	while (ppnts[++i])
		free_pnts(ppnts[i]);
	free(ppnts);
}

void	type_free(va_list args, const char format)
{
	if (format == 'a')
		simplefree(va_arg(args, void *));
	else if (format == 'b')
		free_pnts(va_arg(args, void **));
	else if (format == 'c')
		free_ppnts(va_arg(args, void ***));
}

void	multiple_free(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			if (ft_strchr("abc", *(format + i + 1)))
				type_free(args, *(format + i + 1));
			i++;
		}
		i++;
	}
	va_end(args);
}
