/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:16:43 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/04 16:23:56 by jorteixe         ###   ########.fr       */
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
	map_validator(data->map.map_array, map_copy, data);
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
        {
            free(line); // Free the line if lines is NULL
            return (free_pnts((void **)lines), NULL);
        }
        lines[count++] = line;
        line = get_next_line(fd);
    }
    free(line); // Free the last line read by get_next_line
    lines = realloc(lines, (count + 1) * sizeof(char *));
    lines[count] = NULL;
    return (lines);
}

void	map_validator(char **map_array, char **map_copy, t_data *data)
{
	check_letters(map_array, map_copy);
	check_pe_count(map_array);
	check_c_count(map_array);
	check_size(map_array);
	check_outside_walls(map_array);
	check_path_honor_pabernar(map_array, map_copy, data);
}

void	check_path_honor_pabernar(char **map, char **map_copy, t_data *data)
{
    int		i;
    int		j;

    get_player_pos(data->map.map_array, &(data->player.x), &(data->player.y));
    dfs(map, data->player.x, data->player.y);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C' || map[i][j] == 'E')
                error_handler_2(ERR_MAP_PATH, (void **)map_copy,(void **) map);
            j++;
        }
        i++;
    }
    free_pnts((void **)map); // Free the map after DFS
    free_pnts((void **)map);
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
