/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:11:54 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/07 09:51:02 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	path_validator(t_data *data, int x, int y)
{
	char	c;

	c = data->map.map_array[data->player.x + x][data->player.y + y];
	if (c == '1')
		return (0);
	if (c == 'E' && data->player.collectables != 0)
		return (0);
	if (c == 'E')
		on_destroy(data);
	return (c);
}

void	move_player(t_data *data, int x, int y, void *img)
{
	char	c;

	mlx_put_image_to_window(data->mlx, data->win, img,
		data->player.y * 32, data->player.x * 32);
	c = path_validator(data, x, y);
	if (!c)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->ground.img,
		data->player.y * 32, data->player.x * 32);
	data->map.map_array[data->player.x + x][data->player.y + y] = '0';
	if (c == 'C')
		data->player.collectables--;
	data->player.x += x;
	data->player.y += y;
	mlx_put_image_to_window(data->mlx, data->win, img,
		data->player.y * 32, data->player.x * 32);
	ft_printf("Moves: %d\n", ++data->player.moves);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_d || keysym == XK_Right)
		move_player(data, 0, 1, data->player.right.img);
	else if (keysym == XK_a || keysym == XK_Left)
		move_player(data, 0, -1, data->player.left.img);
	else if (keysym == XK_w || keysym == XK_Up)
		move_player(data, -1, 0, data->player.up.img);
	else if (keysym == XK_s || keysym == XK_Down)
		move_player(data, 1, 0, data->player.down.img);
	if (keysym == XK_Escape)
		on_destroy(data);
	return (0);
}

int	on_destroy(t_data *data)
{
	free_pnts((void **)data->map.map_copy);
	free_pnts((void **)data->map.map_array);
	image_destroy(data);
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
