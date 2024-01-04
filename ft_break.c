/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:05:54 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 13:09:48 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_start(t_game *g, char *file, char **datas)
{
	int		i;
	int		j;
	int		y;

	i = -1;
	y = ft_strlen(datas[6]);
	while (file[++i])
	{
		j = 0;
		while (datas[6][j] == file[i])
		{
			i++;
			j++;
			if(y == j)
				return(i + 1);
		}
	}
	ft_error(g, "ERROR\n -> Problemas con la lectura del archivo\n", 1);
	return (i);
}

void	ft_fill_space(t_game *g, int i)
{
	while(i < g->row)
	{
		g->map = ft_strjoin_gnl(g->map, " ");
		i++;
	}
}

void	ft_break_map(t_game *g, char *fl, char **splited ,int start)
{
	int i;

	i = 7;
	g->map = ft_strdup(splited[6]);
	while(splited[i])
	{
		g->map = ft_strjoin_gnl(g->map, "\n");
		if(fl[start] && fl[start] == '\n')
		{
			ft_fill_space(g, 0);
			start++;
		}
		else
		{
			g->map = ft_strjoin_gnl(g->map, splited[i]);
			ft_fill_space(g, ft_strlen(splited[i]));
			while(fl[start] && fl[start] != '\n')
				start++;
			start++;
			i++;
		}
	}
}

void	ft_break_file(t_game *g, char *file)
{
	char	**splited;
	char	*line;
	int		i;

	g->data = ft_split_n(file, '\n', 6);
	splited = ft_split(file, '\n');
	line = ft_strdup(splited[6]);
	i = 6;
	while(splited[++i])
	{
		line = ft_strjoin_gnl(line, "\n");
		line = ft_strjoin_gnl(line, splited[i]);
	}
	g->row = ft_row_size(line);
	ft_break_map(g, file, splited, ft_map_start(g, file, splited));
	ft_free_double(splited);
	free(line);
}
