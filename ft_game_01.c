/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:11:36 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/20 20:29:11 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda_data(t_game *g)
{
	g->map_x = (int)g->pos.x;
	g->map_y = (int)g->pos.y;
	g->delta_dist.x = 1e30;
	if (g->delta_dist.x != 0)
		g->delta_dist.x = fabs(1.0 / g->ray.x);
	g->delta_dist.y = 1e30;
	if (g->delta_dist.y != 0)
		g->delta_dist.y = fabs(1.0 / g->ray.y);
	g->step_x = 1;
	if (g->ray.x < 0)
	{
		g->step_x = g->step_x * -1;
		g->side_dist.x = (g->pos.x - g->map_x) * g->delta_dist.x;
	}
	else
		g->side_dist.x = (g->map_x + 1.0 - g->pos.x) * g->delta_dist.x;
	g->step_y = 1;
	if (g->ray.y < 0)
	{
		g->step_y = g->step_y * -1;
		g->side_dist.y = (g->pos.y - g->map_y) * g->delta_dist.y;
	}
	else
		g->side_dist.y = (g->map_y + 1.0 - g->pos.y) * g->delta_dist.y;
}

void	ft_dda(t_game *g)
{
	int	hit;

	ft_dda_data(g);
	hit = 0;
	while (!hit)
	{
		if (g->side_dist.x < g->side_dist.y)
		{
			g->side_dist.x += g->delta_dist.x;
			g->map_x += g->step_x;
			g->side = X;
		}
		else
		{
			g->side_dist.y += g->delta_dist.y;
			g->map_y += g->step_y;
			g->side = Y;
		}
		if (g->map[g->map_x][g->map_y] == 1)
			hit = 1;
	}
	if (g->side == X)
		g->perp_wall_dist = (g->side_dist.x - g->delta_dist.x);
	else
		g->perp_wall_dist = (g->side_dist.y - g->delta_dist.y);
}

void	ft_raycast_data(t_game *g, int x)
{
	g->camera_x = 2.0 * x / (double)WIN_WIDTH - 1;
	g->ray.x = g->dir.x + g->plane.x * g->camera_x;
	g->ray.y = g->dir.y + g->plane.y * g->camera_x;
	ft_dda(g);
	g->line_height = (int)(WIN_HEIGHT / g->perp_wall_dist);
	g->draw_start = (int)(-g->line_height / 2.0) + (int)(WIN_HEIGHT / 2.0);
}

int	ft_raycast(void *param)
{
	t_game		*g;
	int			x;

	x = 0;
	g = (t_game *)param;
	ft_move_shape(g);
	while (x < WIN_WIDTH)
	{
		ft_raycast_data(g, x);
		if (g->draw_start < 0)
			g->draw_start = 0;
		g->draw_end = (int)(g->line_height / 2.0) + (int)(WIN_HEIGHT / 2.0);
		if (g->draw_end >= WIN_HEIGHT)
			g->draw_end = WIN_HEIGHT - 1;
		ft_draw_line(g, x);
		ft_texture_loop(g, x);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return (0);
}

void	ft_init_game(t_game *g)
{
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!g->win)
		ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
	g->img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!g->img)
		ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
	g->addr = (int *)mlx_get_data_addr(g->img, &g->bits_per_pixel, \
			&g->line_length, &g->endian);
	g->key_move = -1;
	g->key_rotate = -1;
	g->key_sides = -1;
	g->mouse_move = 0;
	g->turn_direction = -1;
}
