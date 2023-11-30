/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:25:07 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/30 16:21:42 by jorteixe         ###   ########.fr       */
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
		printf("You should write: %s <map_relative_path>\n", argv[0]);
		return (1);
	}
	
	// t_data	data;
	char	**map_array;
	int		i;

	map_array = parse_n_validate_map(argv[1]);
	// data.mlx = mlx_init();
	// if (!data.mlx)
	// 	return (error_handler(ERR_MLX, NULL, NULL));
	// data.win = mlx_new_window(data.mlx, 600, 400, "my window");
	// if (!data.win)
	// 	return (error_handler(ERR_WINDOW, data.mlx, NULL));
	// mlx_loop_hook(data.mlx, &render, &data);
	// mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	// mlx_hook(data.win, DestroyNotify, StructureNotifyMask,&on_destroy,&data);
	// mlx_loop(data.mlx);
	// mlx_destroy_display(data.mlx);
	// free(data.mlx);
	i = 0;
	while (map_array[i] != NULL)
	{
		ft_printf("map_array: %s\n", map_array[i]);
		i++;
	}
	free_pnts((void **)map_array);
	return (0);
}
