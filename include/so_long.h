/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:08:35 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/07 09:49:43 by jorteixe         ###   ########.fr       */
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

typedef struct s_player
{
	int				x;
	int				y;
	int				moves;
	int				collectables;
	t_img			down;
	t_img			left;
	t_img			right;
	t_img			up;
}					t_player;

typedef struct s_map
{
	int				width;
	int				height;
	char			**map_array;
	char			**map_copy;
}					t_map;
typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				color;
	t_img			wall;
	t_img			ground;
	t_img			exit;
	t_img			collectible;
	t_player		player;
	t_map			map;
}					t_data;

/* ************************************************************************** */
/*                                Errors                                      */
/* ************************************************************************** */
# define ERR_MALLOC 1
# define ERR_MLX 2
# define ERR_WINDOW 3
# define ERR_IMAGE 4
# define ERR_MAP_OPEN 5
# define ERR_MAP_CHARS 6
# define ERR_MAP_CHARS2 7
# define ERR_MAP_RECT 8
# define ERR_MAP_WALLS 9
# define ERR_MAP_EXT 10
# define ERR_MAP_PATH 11
# define ERR_MAP_PLAYER 12
# define ERR_MAP_CONSUMABLE 13
# define ERR_MAP_EXIT 14
# define ERR_MAP_PLAYER_COUNT 15
# define ERR_MAP_EXIT_COUNT 16
# define ERR_MAP_CONSUMABLE_COUNT 17

int					error_handler(int error_msg, void *param, void **param2);
int					error_handler_2(int error_msg, void **param, void **param2);
void				error_handler_3(int error_msg, void **param, void **param2);

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

void				image_init(t_data *data);
void				image_draw(t_data *data, int i, int j);
void				image_destroy(t_data *data);

/* ************************************************************************** */
/*                                Moves                                      */
/* ************************************************************************** */

void				move_player(t_data *data, int x, int y, void *img);

/* ************************************************************************** */
/*                                MAP                                        */
/* ************************************************************************** */

void				parse_n_validate_map(char *map_path, t_data *data);
char				**map_parser(int fd, int i, int count, char *map_path);
void				map_validator(char **map_array, char **map_copy,
						t_data *data);
void				check_letters(char **map_array, char **map_copy);
void				check_size(char **map_array, char **map_copy);
void				check_outside_walls(char **map_array, char **map_copy);
void				check_path_honor_pabernar(char **map, char **map_copy,
						t_data *data);
void				check_pe_count(char **map_array, char **map_error,
						int p_count, int e_count);
void				get_player_pos(char **map_array, int *x, int *y);
void				dfs(char **map, int x, int y);
void				reset_map(char **map);
char				**copy_map(char **map);
int					check_c_count(char **map_array, char **map_copy);

/* ************************************************************************** */
/*                                FREE                                        */
/* ************************************************************************** */

void				simplefree(void *pnt);
void				free_pnts(void **pnts);
void				free_ppnts(void ***ppnts);
void				type_free(va_list args, const char format);
void				multiple_free(const char *format, ...);

/* ************************************************************************** */
/*                                UTILS                                       */
/* ************************************************************************** */

int					array_len(char **array);

#endif