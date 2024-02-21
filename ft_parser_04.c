/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:59:11 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/20 20:58:27 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_flood_fill(t_game *g, int size, int curl, int row)
{
	if ((curl < 0) || (curl > size) || (g->ln_map[curl] != '1' \
		&& g->ln_map[curl] != '0' && g->ln_map[curl] != 'X' \
		&& g->ln_map[curl] != g->letter))
		ft_error(g, "ERROR\n -> Brecha en el mapa.\n", 1);
	if (g->ln_map[curl] == '0')
	{
		g->ln_map[curl] = 'X';
		ft_flood_fill(g, size, curl + 1, row);
		ft_flood_fill(g, size, curl - 1, row);
		ft_flood_fill(g, size, curl + row, row);
		ft_flood_fill(g, size, curl - row, row);
	}
}

void	ft_int_matrix(t_game *g)
{
	int	i;
	int	j;
	int	x;

	g->map = ft_calloc(sizeof(int *), (g->map_col + 1));
	if (!g->map)
		ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
	i = -1;
	x = 0;
	while (++i < g->map_col)
	{
		g->map[i] = ft_calloc(sizeof(int), g->map_row + 1);
		if (!g->map[i])
			ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
		j = -1;
		while (g->ln_map[x] && g->ln_map[x] != '\n')
		{
			if (g->ln_map[x] == '0' || g->ln_map[x] == '1')
				g->map[i][++j] = g->ln_map[x] - 48;
			else
				g->map[i][++j] = -1;
			x++;
		}
		x++;
	}
}

void	ft_check_edg(t_game *g)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(g->ln_map);
	while (g->ln_map[i] && g->ln_map[i] != g->letter)
		i++;
	ft_int_matrix(g);
	g->map[(i / g->map_row)][(i % g->map_row) - (i / g->map_row)] = 0;
	if ((g->ln_map[i]) && (g->ln_map[i] == g->letter))
	{
		if (i + 1 <= size && i + 1 > 0 && g->ln_map[i + 1] == '0')
			ft_flood_fill(g, size, i + 1, g->map_row + 1);
		if (i - 1 <= size && i - 1 > 0 && g->ln_map[i - 1] == '0')
			ft_flood_fill(g, size, i - 1, g->map_row + 1);
		if (i - g->map_row <= size && i - g->map_row > 0 && \
			g->ln_map[i + g->map_row] == '0')
			ft_flood_fill(g, size, i + g->map_row, g->map_row + 1);
		if (i + g->map_row <= size && i + g->map_row > 0 && \
			g->ln_map[i - g->map_row] == '0')
			ft_flood_fill(g, size, i - g->map_row, g->map_row + 1);
	}
}

void	ft_check_letter(t_game *g, int i, int j)
{
	if ((g->data[i][j]) &&
	((g->data[i][j] == 'N' && g->data[i][j + 1] == 'O'
	&& g->data[i][j + 2] == ' ') ||
	(g->data[i][j] == 'S' && g->data[i][j + 1] == 'O'
	&& g->data[i][j + 2] == ' ') ||
	(g->data[i][j] == 'W' && g->data[i][j + 1] == 'E'
	&& g->data[i][j + 2] == ' ') ||
	(g->data[i][j] == 'E' && g->data[i][j + 1] == 'A'
	&& g->data[i][j + 2] == ' ')))
		ft_check_wesn(g, g->data[i][j], i, j + 2);
	else if ((g->data[i][j]) &&
	(((g->data[i][j] == 'F' && g->data[i][j + 1] == ' ')) ||
	((g->data[i][j] == 'C' && g->data[i][j + 1] == ' '))))
		ft_check_cf(g, g->data[i][j], i, j + 1);
	else
		ft_error(g, "ERROR\n -> Datos invalidos.\n", 1);
}

void	ft_check_data(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->data && g->data[++i])
	{
		j = 0;
		while (g->data[i][j] && g->data[i][j] == ' ')
			j++;
		ft_check_letter(g, i, j);
	}
	if (!g->n_addr || !g->s_addr || !g->w_addr || !g->e_addr \
		|| !g->c_color || !g->f_color)
		ft_error(g, "ERROR\n -> Datos invalidos.\n", 1);
}
