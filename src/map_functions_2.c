/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:12 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/05 12:25:19 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_letters(char **map_array, char **map_copy)
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
				error_handler(ERR_MAP_CHARS, (void *)map_copy,
					(void **)map_array);
			j++;
		}
		i++;
	}
}

void	check_size(char **map_array, char **map_copy)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		if (ft_strlen(map_array[i]) != ft_strlen(map_array[0]))
		{
			error_handler(ERR_MAP_RECT, (void **)map_copy, (void **)map_array);
		}
		i++;
	}
	if (ft_strlen(map_array[0]) == (size_t)(i))
	{
		error_handler(ERR_MAP_RECT, NULL, (void **)map_array);
	}
}

void	check_outside_walls(char **map_array, char **map_copy)
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
					error_handler_2(ERR_MAP_WALLS, (void **)map_copy,
						(void **)map_array);
			}
			else if (j == 0 || j == (int)ft_strlen(map_array[i]) - 1)
			{
				if (map_array[i][j] != '1')
					error_handler_2(ERR_MAP_WALLS, (void **)map_copy,
						(void **)map_array);
			}
			j++;
		}
		i++;
	}
}

void	check_pe_count(char **map_array, char **map_error, int p_count,
		int e_count)
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
				p_count++;
			if (map_array[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1)
		error_handler_3(ERR_MAP_PLAYER_COUNT, (void **)map_error,
			(void **)map_array);
	if (e_count != 1)
		error_handler_3(ERR_MAP_EXIT_COUNT, (void **)map_error,
			(void **)map_array);
}

void	check_c_count(char **map_array, char **map_error)
{
	int	i;
	int	j;
	int	c_count;

	i = 0;
	c_count = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	if (c_count == 0)
		error_handler_3(ERR_MAP_CONSUMABLE_COUNT, (void **)map_error,
			(void **)map_array);
}
