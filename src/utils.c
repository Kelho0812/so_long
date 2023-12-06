/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:25:10 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/06 16:03:08 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	image_init(t_data *data)
{
	data->player.down.img = mlx_xpm_file_to_image(data->mlx, "player_up.xpm", &data->player.down.width, &data->player.down.height);
	data->player.up.img = mlx_xpm_file_to_image(data->mlx, "player_down.xpm", &data->player.up.width, &data->player.up.height);
	data->player.right.img = mlx_xpm_file_to_image(data->mlx, "player_left.xpm", &data->player.right.width, &data->player.right.height);
	data->player.left.img = mlx_xpm_file_to_image(data->mlx, "player_right.xpm", &data->player.left.width, &data->player.left.height);
	data->ground.img = mlx_xpm_file_to_image(data->mlx, "ground.xpm", &data->ground.width, &data->ground.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "wall.xpm", &data->wall.width, &data->wall.height);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "exit.xpm", &data->exit.width, &data->exit.height);
	data->collectible.img = mlx_xpm_file_to_image(data->mlx, "collectible.xpm", &data->collectible.width, &data->collectible.height);
}

void	image_draw (t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map_array[i] != NULL)
	{
		j = 0;
		while (data->map.map_array[i][j] != '\0')
		{
			if (data->map.map_array[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall.img, j * 32, i * 32);
			else if (data->map.map_array[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->ground.img, j * 32, i * 32);
			else if (data->map.map_array[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->player.up.img, j * 32, i * 32);
			else if (data->map.map_array[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit.img, j * 32, i * 32);
			else if (data->map.map_array[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->collectible.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}


void	image_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.up.img);
	mlx_destroy_image(data->mlx, data->player.down.img);
	mlx_destroy_image(data->mlx, data->player.left.img);
	mlx_destroy_image(data->mlx, data->player.right.img);
	mlx_destroy_image(data->mlx, data->ground.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_image(data->mlx, data->collectible.img);
}
