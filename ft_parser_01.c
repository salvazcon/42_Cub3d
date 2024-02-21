/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:54:26 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/20 20:29:18 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_read(int fd)
{
	char	*buffer;
	char	*text;
	int		readed;

	text = ft_calloc(sizeof(char), 1);
	if (!text)
		return (NULL);
	buffer = ft_calloc(sizeof(char), 2);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read (fd, buffer, 1);
		if (readed == -1)
		{
			free(buffer);
			free(text);
			return (NULL);
		}
		buffer[readed] = '\0';
		text = ft_strjoin_gnl(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*ft_read_file(t_game *g, char *file)
{
	char	*f;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
	f = ft_read(fd);
	if (!f || !f[0])
	{
		close(fd);
		ft_error(g, "ERROR\n -> Archivo vacio o problema inesperado.\n", 1);
	}
	close(fd);
	return (f);
}

void	ft_check_ext(t_game *g, char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] != '.' || file[i - 3] != 'c' \
	|| file[i - 2] != 'u' || file[i - 1] != 'b')
		ft_error(g, "ERROR\n -> Extension incorrecta.\n", 1);
}
