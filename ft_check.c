/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:10:34 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 18:55:16 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_row_size(char *map)
{
	int	i;
	int	j;
	int	row;

	i = -1;
	j = 0;
	row = 0;
	while (map[++i])
	{
		j++;
		if (map[i] == '\n')
		{
			if (j > row)
				row = j;
			j = 0;
		}
	}
	return (row);
}

void	ft_flood_fill(t_game *g, int size, int curl, int start)
{
	if ((curl < 0) || (curl > size) || (g->map[curl] != '1' \
		&& g->map[curl] != '0' && g->map[curl] != 'X' \
		&& g->map[curl] != g->map[start]))
		ft_error(g, "ERROR\n -> Hay una brecha en el mapa.\n", 1);
	if (g->map[curl] == '0')
	{
		g->map[curl] = 'X';
		ft_flood_fill(g, size, curl + 1, start);
		ft_flood_fill(g, size, curl - 1, start);
		ft_flood_fill(g, size, curl + g->row, start);
		ft_flood_fill(g, size, curl - g->row, start);
	}
}

void	ft_check_edg(t_game *g)
{
	int	i;
	int	size;

	i = 0;
	g->row = ft_row_size(g->map);
	size = ft_strlen(g->map);
	while (g->map[i] && g->map[i] != 'N' && g->map[i] != 'S' \
		&& g->map[i] != 'E' && g->map[i] != 'W')
		i++;
	if ((g->map[i]) && (g->map[i] == 'N' || g->map[i] == 'S' || \
		g->map[i] == 'E' || g->map[i] == 'W'))
	{
		if (i + 1 <= size && i + 1 > 0 && g->map[i + 1] == '0')
			ft_flood_fill(g, size, i + 1, i);
		if (i - 1 <= size && i - 1 > 0 && g->map[i - 1] == '0')
			ft_flood_fill(g, size, i - 1, i);
		if (i - g->row <= size && i - g->row > 0 && g->map[i + g->row] == '0')
			ft_flood_fill(g, size, i + g->row, i);
		if (i + g->row <= size && i + g->row > 0 && g->map[i - g->row] == '0')
			ft_flood_fill(g, size, i - g->row, i);
	}
}

void	ft_check_car(t_game *g)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (g->map[++i])
	{
		if (g->map[i] == 'N' || g->map[i] == 'S' || \
			g->map[i] == 'E' || g->map[i] == 'W')
			c++;
		if (g->map[i] != 'N' && g->map[i] != 'S' && g->map[i] != 'E' \
			&& g->map[i] != 'W' && g->map[i] != ' ' && g->map[i] != '\n' \
			&& g->map[i] != '1' && g->map[i] != '0')
			ft_error(g, "ERROR\n -> Caracter invalido en el mapa, lol !!\n", 1);
	}
	if (c != 1)
		ft_error(g, "ERROR\n -> El mapa es invalido.\n", 1);
}

void	ft_check_map(t_game *g)
{
	ft_check_car(g);
	ft_check_edg(g);
}
