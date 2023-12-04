/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:31:27 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/04 15:58:37 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

char	**copy_map(char **map)
{
    int		i;
    char	**copy;

    i = 0;
    while (map[i])
        i++;
    copy = (char **)malloc((i + 1) * sizeof(char *));
    if (!copy)
        return (NULL);
    i = 0;
    while (map[i])
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            free_pnts((void **)copy); // Free the memory if strdup fails
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}
