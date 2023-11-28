/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:04:51 by jorteixe          #+#    #+#             */
/*   Updated: 2023/10/06 13:18:42 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	skip_spaces(unsigned char *str, int *ptr);
static int	check_plus_minus(unsigned char *str, int *ptr);

int	ft_atoi(const char *str)
{
	unsigned char	*s;
	int				*ptr;
	int				i;
	int				minus_count;
	int				n;

	s = (unsigned char *)str;
	i = 0;
	n = 0;
	minus_count = 0;
	ptr = &i;
	skip_spaces(s, ptr);
	minus_count = check_plus_minus(s, ptr);
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
	{
		n = n * 10;
		n = n + (s[i] - '0');
		i++;
	}
	if (minus_count == -1)
		n = n * (-1);
	return (n);
}

static void	skip_spaces(unsigned char *str, int *ptr)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	*ptr = i;
}

static int	check_plus_minus(unsigned char *str, int *ptr)
{
	int	i;

	i = *ptr;
	if (str[i] == '+')
	{
		i++;
	}
	else if (str[i] == '-')
	{
		i++;
		*ptr = i;
		return (-1);
	}
	*ptr = i;
	return (0);
}
