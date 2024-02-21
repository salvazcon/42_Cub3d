/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:46:32 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/26 17:01:28 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_color(t_game *g)
{
	int	color;

	color = 0;
	if (g->side == 0 && g->ray.x > 0)
		color = *(g->n_addr->mlx_addr + (g->mlx_x * g->texy + g->texx));
	else if (g->side == 0 && g->ray.x < 0)
		color = *(g->s_addr->mlx_addr + (g->mlx_x * g->texy + g->texx));
	else if (g->side == 1 && g->ray.y > 0)
		color = *(g->w_addr->mlx_addr + (g->mlx_x * g->texy + g->texx));
	else if (g->side == 1 && g->ray.y < 0)
		color = *(g->e_addr->mlx_addr + (g->mlx_x * g->texy + g->texx));
	return (color);
}

void	ft_texture_data(t_game *g)
{
	double	wallx;

	if (g->side == 0)
		wallx = g->pos.y + g->perp_wall_dist * g->ray.y;
	else
		wallx = g->pos.x + g->perp_wall_dist * g->ray.x;
	wallx -= floor(wallx);
	g->texx = (int)(wallx * (double)g->mlx_y);
	if (g->side == 0 && g->ray.x > 0)
		g->texx = g->mlx_y - g->texx - 1;
	if (g->side == 1 && g->ray.y < 0)
		g->texx = g->mlx_y - g->texx - 1;
}

void	ft_texture_loop(t_game *g, int x)
{
	double	texpos;
	double	step;
	int		color;
	int		y;

	color = 0;
	ft_texture_data(g);
	step = 1.0 * g->mlx_x / g->line_height;
	texpos = (g->draw_start - WIN_HEIGHT / 2 + g->line_height / 2) * step;
	y = g->draw_start;
	while (y < g->draw_end + 1)
	{
		g->texy = (int)texpos & (g->mlx_x - 1);
		texpos += step;
		color = ft_color(g);
		if (g->side == 1)
			color = (color >> 1) & 8355711;
		g->addr[y * WIN_WIDTH + x] = color;
		y++;
	}
}

void	ft_draw_line(t_game *g, int x)
{
	int	y;

	y = 0;
	while (y < g->draw_start)
	{
		g->addr[y * WIN_WIDTH + x] = g->c_color;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		g->addr[y * WIN_WIDTH + x] = g->f_color;
		y++;
	}
}
