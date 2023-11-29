#include "../include/so_long.h"

int	main(void)
{
	t_data	data;

	/* Create the data */
	data.mlx = mlx_init();
	if (!data.mlx)
		return (error_handler("mlx_error", NULL));
	data.img.img = mlx_xpm_file_to_image(data.mlx, "Rock1_1.xpm",
			&data.img.width, &data.img.height);
	if (!data.img.img)
		return (error_handler("image_error", data.mlx));

	data.floor.img = mlx_xpm_file_to_image(data.mlx, "Map_tile_23.xpm",
			&data.floor.width, &data.floor.height);
	if (!data.floor.img)
		return (error_handler("image_error", data.mlx));
	/* Create the window */
	data.win = mlx_new_window(data.mlx, data.floor.width * 30, data.floor.height * 30,
			"my window");
	if (!data.win)
		return (error_handler("window_error", data.mlx));
	/* Setup hooks */
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx);
	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
