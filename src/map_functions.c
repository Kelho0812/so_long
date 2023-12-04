/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:16:43 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/04 15:07:10 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <errno.h>

void	parse_n_validate_map(char *map_path, t_data *data)
{
	int		fd;
	char	**map_copy;

	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
		error_handler_2(ERR_MAP_EXT, NULL, NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_handler(ERR_MAP_OPEN, NULL, NULL);
	data->map.map_array = map_parser(fd);
	close(fd);
	data->map.width = ft_strlen(data->map.map_array[0]);
	data->map.height = array_len(data->map.map_array);
	map_copy = copy_map(data->map.map_array);
	map_validator(data->map.map_array, data);
	data->map.map_array = copy_map(map_copy);
	free_pnts((void **)map_copy);
}

char	**map_parser(int fd)
{
	char	**lines;
	char	*line;
	int		count;

	count = 0;
	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (count == 0)
			lines = malloc(sizeof(char *));
		else
			lines = realloc(lines, (count + 1) * sizeof(char *));
		if (lines == NULL)
			return (free(line), free_pnts((void **)lines), NULL);
		lines[count++] = line;
		line = get_next_line(fd);
	}
	lines = realloc(lines, (count + 1) * sizeof(char *));
	lines[count] = NULL;
	return (lines);
}

void	map_validator(char **map_array, t_data *data)
{
	check_letters(map_array);
	check_pec_count(map_array);
	check_exit_player_collectible(map_array);
	check_size(map_array);
	check_outside_walls(map_array);
	check_path_honor_pabernar(map_array, data);
}

void	check_letters(char **map_array)
{
	int	i;
	int	j;

	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] != '0' && map_array[i][j] != '1'
				&& map_array[i][j] != 'C' && map_array[i][j] != 'E'
				&& map_array[i][j] != 'P' && map_array[i][j] != '\n')
				error_handler(ERR_MAP_CHARS, NULL, (void **)map_array);
			j++;
		}
		i++;
	}
}

void	check_exit_player_collectible(char **map_array)
{
	int		i;
	int		j;
	bool	p;
	bool	c;
	bool	e;

	p = false;
	c = false;
	e = false;
	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'P')
				p = true;
			if (map_array[i][j] == 'C')
				c = true;
			if (map_array[i][j] == 'E')
				e = true;
			j++;
		}
		i++;
	}
	if (p == false || c == false || e == false)
		error_handler(ERR_MAP_CHARS2, NULL, (void **)map_array);
}

void	check_size(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		if (ft_strlen(map_array[i]) != ft_strlen(map_array[0]))
		{
			error_handler(ERR_MAP_RECT, NULL, (void **)map_array);
		}
		i++;
	}
	if (ft_strlen(map_array[0]) == (size_t)(i))
	{
		error_handler(ERR_MAP_RECT, NULL, (void **)map_array);
	}
}

void	check_outside_walls(char **map_array)
{
	int	i;
	int	j;

	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (i == 0 || i == array_len(map_array) - 1)
			{
				if (map_array[i][j] != '1')
					error_handler_2(ERR_MAP_WALLS, NULL, (void **)map_array);
			}
			else if (j == 0 || j == (int)ft_strlen(map_array[i]) - 1)
			{
				if (map_array[i][j] != '1')
					error_handler_2(ERR_MAP_WALLS, NULL, (void **)map_array);
			}
			j++;
		}
		i++;
	}
}

void	dfs(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] != 'P')
		map[x][y] = 'V';
	dfs(map, x - 1, y);
	dfs(map, x + 1, y);
	dfs(map, x, y - 1);
	dfs(map, x, y + 1);
}

void	check_path_honor_pabernar(char **map, t_data *data)
{
	char	**original_map;
	int		i;
	int		j;

	get_player_pos(data->map.map_array, &(data->player.x), &(data->player.y));
	original_map = copy_map(map);
	dfs(map, data->player.x, data->player.y);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				error_handler_2(ERR_MAP_PATH, NULL, (void **)original_map);
			j++;
		}
		i++;
	}
	map = copy_map(original_map);
	free_pnts((void **)original_map);
	return ;
}

void	get_player_pos(char **map_array, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	reset_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'V')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	copy[i] = NULL;
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_pnts((void **)copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	check_pec_count(char **map_array)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;
	int	c_count;

	i = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'P')
				p_count++;
			if (map_array[i][j] == 'E')
				e_count++;
			if (map_array[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1)
		error_handler_3(ERR_MAP_PLAYER_COUNT, NULL, (void **)map_array);
	if (e_count != 1)
		error_handler_3(ERR_MAP_EXIT_COUNT, NULL, (void **)map_array);
	if (c_count == 0)
		error_handler_3(ERR_MAP_CONSUMABLE_COUNT, NULL, (void **)map_array);
	return ;
}
