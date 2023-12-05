/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:25:20 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/05 12:43:02 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_handler(int error_msg, void *param, void **param2)
{
	if (error_msg == ERR_MALLOC)
		return (ft_printf("Malloc Error\n"), free(param), 1);
	else if (error_msg == ERR_MLX)
		ft_printf("MLX Error\n");
	else if (error_msg == ERR_WINDOW)
		return (ft_printf("Window Error\n"), free(param), 1);
	else if (error_msg == ERR_IMAGE)
		ft_printf("Image Error\n");
	else if (error_msg == ERR_MAP_CHARS)
	{
		ft_printf("Map Error (Wrong Chars)\n");
		multiple_free("%b %b", param, param2);
	}
	else if (error_msg == ERR_MAP_RECT)
	{
		ft_printf("Map Error (Not a Rectangle)\n");
		multiple_free("%b %b", param, param2);
	}
	exit(1);
}

int	error_handler_2(int error_msg, void **param, void **param2)
{
	if (error_msg == ERR_MAP_WALLS)
	{
		ft_printf("Map Error (Not surrounded by walls)\n");
		multiple_free("%b %b", param, param2);
	}
	else if (error_msg == ERR_MAP_EXT)
	{
		ft_printf("Map Error (Wrong Extension)\n");
	}
	else if (error_msg == ERR_MAP_CHARS2)
	{
		multiple_free("%b%b", param, param2);
		ft_printf("Map Error (No Exit, Player or Consumable)\n");
	}
	else if (error_msg == ERR_MAP_PATH)
	{
		multiple_free("%b %b", param, param2);
		ft_printf("Map Error (No Path to Exit or Consumable)\n");
	}
	else if (error_msg == ERR_MAP_OPEN)
	{
		ft_printf("Map Error (Can't open file)\n");
	}
	exit(1);
}

void	error_handler_3(int error_msg, void **param, void **param2)
{
	if (error_msg == ERR_MAP_PLAYER_COUNT)
	{
		ft_printf("Map Error (Incorrect number of P)\n");
		multiple_free("%b %b", param, param2);
	}
	else if (error_msg == ERR_MAP_EXIT_COUNT)
	{
		ft_printf("Map Error (Incorrect number of E)\n");
		multiple_free("%b %b", param, param2);
	}
	else if (error_msg == ERR_MAP_CONSUMABLE_COUNT)
	{
		ft_printf("Map Error (Incorrect number of C)\n");
		multiple_free("%b %b", param, param2);
	}
	exit(1);
}
