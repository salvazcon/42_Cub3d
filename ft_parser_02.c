/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:05:54 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/21 16:56:00 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_row_size(char *map)
{
	int	i;
	int	j;
	int	row;

	i = 0;
	j = 0;
	row = 0;
	while (map[i])
	{
		if (!map[i + 1] || map[i + 1] == '\n')
		{
			if (j > row)
				row = j;
			j = 0;
		}
		else
			j++;
		i++;
	}
	return (row);
}

void	ft_fill_space(t_game *g, int i)
{
	while (i < g->map_row)
	{
		g->ln_map = ft_strjoin_gnl(g->ln_map, " ");
		i++;
	}
}

int	ft_find_map_start(char *file, char **datas)
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
			if (y == j)
				return (i + 1);
		}
	}
	return (i);
}

void	ft_break_map(t_game *g, char *file, char **splited, int start)
{
	int	i;

	i = 7;
	g->map_col = 1;
	g->ln_map = ft_strdup(splited[6]);
	ft_fill_space(g, ft_strlen(splited[6]));
	while (splited[i])
	{
		g->ln_map = ft_strjoin_gnl(g->ln_map, "\n");
		if (file[start] && file[start] == '\n')
		{
			ft_fill_space(g, 0);
			start++;
		}
		else
		{
			g->ln_map = ft_strjoin_gnl(g->ln_map, splited[i]);
			ft_fill_space(g, ft_strlen(splited[i]));
			start = start + 1 + ft_strlen(splited[i]);
			i++;
		}
		g->map_col++;
	}
}

void	ft_break_file(t_game *g, char *file)
{
	char	**splited;
	char	*line;
	int		i;

	splited = ft_split(file, '\n');
	if (!splited || !splited[5] || !splited[6])
		ft_error(g, "ERROR\n -> Datos invalidos.\n", 1);
	g->data = ft_split_n(file, '\n', 6);
	i = 6;
	line = ft_strdup(splited[6]);
	while (splited[++i])
	{
		line = ft_strjoin_gnl(line, "\n");
		line = ft_strjoin_gnl(line, splited[i]);
	}
	g->map_row = ft_row_size(line);
	free(line);
	ft_break_map(g, file, splited, ft_find_map_start(file, splited));
	ft_free_double(splited);
}
