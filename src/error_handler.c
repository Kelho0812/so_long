/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:25:20 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/30 16:27:24 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_handler(int error_msg, void *param, void **param2)
{
	if (error_msg == ERR_MALLOC)
		return(ft_printf("Malloc Error\n"),free(param), 1);
	else if (error_msg == ERR_MLX)
		ft_printf("MLX Error\n");
	else if (error_msg == ERR_WINDOW)
	{
		ft_printf("Window Error\n");
		free(param);
	}
	else if (error_msg == ERR_IMAGE)
		ft_printf("Image Error\n");
	else if (error_msg == ERR_MAP_CHARS )
	{
		ft_printf("Map Error (Wrong Chars)\n");
		free_pnts(param2);
		exit(1);
	}
	else if (error_msg == ERR_MAP_RECT)
	{
		ft_printf("Map Error (Not a Rectangle)\n");
		free_pnts(param2);
		exit(1);
	}
	return (0);
}
