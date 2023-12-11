/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:32:26 by jorteixe          #+#    #+#             */
/*   Updated: 2023/12/11 13:21:14 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(int fd)
{
	char		*buffer_str;
	char		*stringzz;
	static char	*str;
	int			n;

	n = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_str = ft_calloc_get(BUFFER_SIZE + 1, 1);
	while (!has_newline(str) && n > 0)
	{
		n = read(fd, buffer_str, BUFFER_SIZE);
		if (n < 0)
		{
			return (norminettenz(&str, &buffer_str));
		}
		buffer_str[n] = '\0';
		str = ft_strjoin_get(str, buffer_str);
	}
	stringzz = ft_substr_get(str);
	str = ft_clean_str(str);
	free(buffer_str);
	return (stringzz);
}

int	has_newline(char *str)
{
	int	i;

	if (!str)
	{
		return (0);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_clean_str(char *str)
{
	int		i;
	int		j;
	char	*s1;

	i = 0;
	j = 0;
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	s1 = ft_calloc_get(ft_strlen(str) - i + 1, 1);
	while (str[i])
		s1[j++] = str[++i];
	s1[j] = '\0';
	free(str);
	return (s1);
}

char	*norminettenz(char **str, char **buffer_str)
{
	free(*buffer_str);
	free(*str);
	*str = NULL;
	return (NULL);
}
