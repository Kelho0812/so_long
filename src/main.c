/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:25:07 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/07 10:11:59 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Create the data & check for errors*/
/* Create the window & check for errors*/
/* Setup hooks */
/* Exit the loop if there's no window left, and clean the memory */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("You should write: %s <map_relative_path>\n", argv[0]);
		return (1);
	}
	parse_n_validate_map(argv[1], &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (error_handler(ERR_MLX, NULL, NULL));
	data.win = mlx_new_window(data.mlx, 32 * data.map.width, 32
			* data.map.height, "so_long");
	if (!data.win)
		return (error_handler(ERR_WINDOW, data.mlx, NULL));
	image_init(&data);
	image_draw(&data, 0, 0);
	data.player.moves = 0;
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx);
	image_destroy(&data);
	on_destroy(&data);
	return (0);
}
