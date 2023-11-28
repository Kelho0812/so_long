/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:56:18 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/09 17:10:46 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c);
static int	string_size(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str_array = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!str_array)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			str_array[j] = ft_substr(s, i, string_size(s + i, c));
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	str_array[j] = 0;
	return (str_array);
}

static int	word_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		if (s[i] != '\0')
		{
			counter++;
		}
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
	}
	return (counter);
}

static int	string_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}
