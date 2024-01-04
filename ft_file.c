/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:54:26 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 18:48:51 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_read(int fd)
{
	char	*buffer;
	char	*line;
	int		readed;

	line = ft_calloc(sizeof(char), 1);
	if (!line)
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
			return (NULL);
		}
		buffer[readed] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_read_file(t_game *g, char *file)
{
	char	*f;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(g, "ERROR\n -> Problemas con archivo\n", 1);
	f = ft_read(fd);
	if (!f)
		ft_error(g, "ERROR\n -> Problemas con la lectura del archivo\n", 1);
	close(fd);
	return (f);
}

void	ft_check_ext(t_game *g, char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] != '.' || file[i - 3] != 'c' \
	|| file[i - 2] != 'u' || file[i - 1] != 'b')
		ft_error(g, "ERROR\n -> Extension incorrecta, espabila bro!!\n", 1);
}
