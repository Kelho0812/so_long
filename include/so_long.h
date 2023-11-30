/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:08:35 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/30 14:33:33 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <time.h>
# include <unistd.h>

# define RED_PIXEL 0x00FF0000
# define GREEN_PIXEL 0x0000FF00

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
	int				x;
	int				y;
	char			type;
	char			*path;
	struct s_img	*next;
}					t_img;
typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				color;
	t_img			img;
}					t_data;

/* ************************************************************************** */
/*                                Errors                                      */
/* ************************************************************************** */
# define ERR_MALLOC 1
# define ERR_MLX 2
# define ERR_WINDOW 3
# define ERR_IMAGE 4
# define ERR_MAP_CHARS 5
# define ERR_MAP_RECT 6
# define ERR_MAP_WALLS 7

int					error_handler(int error_msg, void *param, void **param2);

/* ************************************************************************** */
/*                                Events                                      */
/* ************************************************************************** */

int					handle_keypress(int keysym, t_data *data);
int					on_destroy(t_data *data);
void				img_pix_put(t_img *img, int x, int y, int color);
int					on_mouse_enter(int x, int y, t_data *data);
int					on_mouse_exit(int x, int y, t_data *data);
int					key_press(int keycode, t_data *data);

/* ************************************************************************** */
/*                                RENDER                                      */
/* ************************************************************************** */

int					render_and_change_color(t_data *data);
int					render(t_data *data);
int					change_color(t_data *data);

/* ************************************************************************** */
/*                                MAP                                        */
/* ************************************************************************** */

char				**parse_n_validate_map(void);
char				**map_parser(int fd);
void				map_validator(char **map_array);
void				check_letters(char **map_array);
void				check_size(char **map_array);

/* ************************************************************************** */
/*                                FREE                                        */
/* ************************************************************************** */

void				simplefree(void *pnt);
void				free_pnts(void **pnts);
void				free_ppnts(void ***ppnts);
void				type_free(va_list args, const char format);
void				multiple_free(const char *format, ...);
#endif