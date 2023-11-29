#include "../include/so_long.h"

int	error_handler(char *error_msg, void *param)
{
	if (strcmp(error_msg, "mlx_error") == 0)
		ft_printf("MLX Error\n");
	else if (strcmp(error_msg, "window_error") == 0)
	{
		ft_printf("Window Error\n");
		free(param);
	}
	else if (strcmp(error_msg, "image_error") == 0)
	{
		ft_printf("Image Error\n");
	}
	
	return (1);
}