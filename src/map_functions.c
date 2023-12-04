/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:16:43 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/04 08:54:54 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <errno.h>

char	**parse_n_validate_map(char *map_path)
{
	int		fd;
	char	**map_array;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_handler(ERR_MAP_OPEN, NULL, NULL);
	map_array = map_parser(fd);
	close(fd);
	map_validator(map_array);
	return (map_array);
}

char	**map_parser(int fd)
{
	char	**lines;
	char	*line;
	int		count;

	lines = NULL;
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (count == 0)
		{
			lines = malloc(sizeof(char *));
			if (lines == NULL)
				return (free(line), free_pnts((void **)lines), NULL);
		}
		else
		{
			lines = realloc(lines, (count + 1) * sizeof(char *));
			if (lines == NULL)
				return (free(line), free_pnts((void **)lines), NULL);
		}
		lines[count++] = line;
	}
	free(line);
	lines = realloc(lines, (count + 1) * sizeof(char *));
	return (lines[count] = NULL, lines);
}

void	map_validator(char **map_array)
{
	check_letters(map_array);
	check_size(map_array);
	check_outside_walls(map_array);
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