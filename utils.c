/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:46:11 by saazcon-          #+#    #+#             */
/*   Updated: 2023/11/29 15:27:24 by saazcon-         ###   ########.fr       */
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

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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

char	*ft_substr(char *s, int start, int len)
{
	char	*dst;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start)) 
		len = ft_strlen(s) - start;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (0);
	i = 0;
	while (len > i)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
