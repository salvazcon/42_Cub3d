/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:46:11 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 17:15:04 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		val;

	i = 0;
	sign = 1;
	val = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = (sign * -1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = (val * 10);
		val = (val + (str[i] - 48));
		i++;
	}
	return (val * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin_gnl(char *stash, char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (!stash || !buff)
		return (NULL);
	str = ft_calloc(sizeof(char), ft_strlen(stash) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (stash[++i])
		str[i] = stash[i];
	j = -1;
	while (buff[++j])
		str[i + j] = buff[j];
	free(stash);
	return (str);
}
