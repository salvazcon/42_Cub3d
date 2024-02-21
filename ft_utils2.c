/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:38:24 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/18 19:29:38 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
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

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*dst;
	int		i;

	if (!s)
		return (0);
	if ((int)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - (int)start))
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
