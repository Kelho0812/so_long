#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_img;
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		color;
	time_t	last_color_change;
	t_img	img;
	t_img	floor;
	t_img	character;
	t_img	collectible;
}			t_data;

/* ************************************************************************** */
/*                                Events                                      */
/* ************************************************************************** */

int			handle_keypress(int keysym, t_data *data);
int			on_destroy(t_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);
int			error_handler(char *error_msg, void *param);
int			on_mouse_enter(int x, int y, t_data *data);
int			on_mouse_exit(int x, int y, t_data *data);
int			key_press(int keycode, t_data *data);

/* ************************************************************************** */
/*                                RENDER                                      */
/* ************************************************************************** */

int			render_and_change_color(t_data *data);
int			render(t_data *data);
int			change_color(t_data *data);

#endif