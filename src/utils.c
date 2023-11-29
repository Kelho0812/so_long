#include "../include/so_long.h"



int	render(t_data *data)
{
	int i = 0;
	int j = 0;
	 if (data->win != NULL)
	{
		while (j < 30)
		{
			i = 0;
			while (i < 30)
			{
				mlx_put_image_to_window(data->mlx, data->win, data->floor.img, data->floor.width * i, data->floor.height * j);
				i++;			
			}
			j++;
		}
		
	}
		
		// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
    return (0);
}