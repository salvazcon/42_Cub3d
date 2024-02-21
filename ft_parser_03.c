/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:10:34 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/20 20:26:56 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_data_ew(t_game *g)
{
	if (g->letter == 'E')
	{
		g->dir.x = 0;
		g->dir.y = 1;
		g->plane.x = 0.66;
		g->plane.y = 0;
		g->rot = 90;
	}
	else if (g->letter == 'W')
	{
		g->dir.x = 0;
		g->dir.y = -1;
		g->plane.x = -0.66;
		g->plane.y = 0;
		g->rot = 270;
	}
}

void	ft_data_nsew(t_game *g)
{
	if (g->letter == 'N')
	{
		g->dir.x = -1;
		g->dir.y = 0;
		g->plane.x = 0;
		g->plane.y = 0.66;
		g->rot = 180;
	}
	else if (g->letter == 'S')
	{
		g->dir.x = 1;
		g->dir.y = 0;
		g->plane.x = 0;
		g->plane.y = -0.66;
		g->rot = 0;
	}
	else
		ft_data_ew(g);
}

void	ft_check_car(t_game *g)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (g->ln_map[++i])
	{
		if (g->ln_map[i] == 'N' || g->ln_map[i] == 'S' || \
			g->ln_map[i] == 'E' || g->ln_map[i] == 'W')
		{
			g->letter = g->ln_map[i];
			g->pos.x = (i / g->map_row) + 0.25;
			g->pos.y = (i % g->map_row) - (i / g->map_row) + 0.25;
			ft_data_nsew(g);
			c++;
		}
		if (g->ln_map[i] != 'N' && g->ln_map[i] != 'S' \
		&& g->ln_map[i] != 'E' && g->ln_map[i] != 'W' \
		&& g->ln_map[i] != ' ' && g->ln_map[i] != '\n' \
		&& g->ln_map[i] != '1' && g->ln_map[i] != '0')
			ft_error(g, "ERROR\n -> Caracter invalido.\n", 1);
	}
	if (c != 1)
		ft_error(g, "ERROR\n -> Caracter extra.\n", 1);
}
