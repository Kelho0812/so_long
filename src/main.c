/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:25:07 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/06 17:10:31 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Create the data & check for errors*/
/* Create the window & check for errors*/
/* Setup hooks */
/* Exit the loop if there's no window left, and clean the memory */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("You should write: %s <map_relative_path>\n", argv[0]);
		return (1);
	}
	t_data	data;
	// int		i;

	parse_n_validate_map(argv[1], &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (error_handler(ERR_MLX, NULL, NULL));
	data.win = mlx_new_window(data.mlx, 32*data.map.width, 32*data.map.height, "so_long");
	if (!data.win)
		return (error_handler(ERR_WINDOW, data.mlx, NULL));
	image_init(&data);
	image_draw(&data);
	data.player.moves = 0;
	// mlx_put_image_to_window(data.mlx, data.win, data.img.img, 30, 30);
	// data.ground.img = mlx_xpm_file_to_image(data.mlx, "Rock1_1.xpm", &data.img.width, &data.img.height);
	// mlx_put_image_to_window(data.mlx, data.win, data.img.img, 50, 30);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,&on_destroy,&data);
	mlx_loop(data.mlx);
	image_destroy(&data);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	// if (!*data.map.map_array)
	// 	ft_printf("map_array is NULL\n");
	// i = 0;
	// while (data.map.map_array[i] != NULL)
	// {
	// 	ft_printf("map_array: %s\n", data.map.map_array[i]);
	// 	i++;
	// }
	free_pnts((void **)data.map.map_copy);
	free_pnts((void **)data.map.map_array);
	return ((void)argc, (void)argv, 0);
}
