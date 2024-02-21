/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:47:14 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/26 16:54:24 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_back_and_forth(t_game *g, int keycode)
{
	if (keycode == 13)
	{
		if (g->map[(int)(g->pos.x + g->dir.x * MOVSPEED)][(int)g->pos.y] == 0)
			g->pos.x += g->dir.x * MOVSPEED;
		if (g->map[(int)g->pos.x][(int)(g->pos.y + g->dir.y * MOVSPEED)] == 0)
			g->pos.y += g->dir.y * MOVSPEED;
	}
	else if (keycode == 1)
	{
		if (g->map[(int)(g->pos.x - g->dir.x * MOVSPEED)][(int)g->pos.y] == 0)
			g->pos.x -= g->dir.x * MOVSPEED;
		if (g->map[(int)g->pos.x][(int)(g->pos.y - g->dir.y * MOVSPEED)] == 0)
			g->pos.y -= g->dir.y * MOVSPEED;
	}
}

void	ft_move_sideways(t_game *g, int keycode)
{
	if (keycode == 2)
	{
		if (g->map[(int)(g->pos.x + g->plane.x * MOVSPEED)][(int)g->pos.y] == 0)
			g->pos.x += g->plane.x * MOVSPEED;
		if (g->map[(int)g->pos.x][(int)(g->pos.y + g->plane.y * MOVSPEED)] == 0)
			g->pos.y += g->plane.y * MOVSPEED;
	}
	else if (keycode == 0)
	{
		if (g->map[(int)(g->pos.x - g->plane.x * MOVSPEED)][(int)g->pos.y] == 0)
			g->pos.x -= g->plane.x * MOVSPEED;
		if (g->map[(int)g->pos.x][(int)(g->pos.y - g->plane.y * MOVSPEED)] == 0)
			g->pos.y -= g->plane.y * MOVSPEED;
	}
}

void	ft_rot_right(t_game *g)
{
	double	aux_dirx;
	double	aux_planex;

	if (g->mouse_move)
	{
		g->mouse_move = 0;
		g->key_rotate = -1;
	}
	g->turn_direction = -1;
	g->rot = g->rot + g->turn_direction * (ROTSPEED * 180 / M_PI);
	aux_dirx = g->dir.x;
	g->dir.x = g->dir.x * cos(-ROTSPEED) - g->dir.y * sin(-ROTSPEED);
	g->dir.y = aux_dirx * sin(-ROTSPEED) + g->dir.y * cos(-ROTSPEED);
	aux_planex = g->plane.x;
	g->plane.x = g->plane.x * cos(-ROTSPEED) - g->plane.y * sin(-ROTSPEED);
	g->plane.y = aux_planex * sin(-ROTSPEED) + g->plane.y * cos(-ROTSPEED);
}

void	ft_rot_left_right(t_game *g, int keycode)
{
	double	aux_dirx;
	double	aux_planex;

	if (keycode == 124)
		ft_rot_right(g);
	else if (keycode == 123)
	{
		if (g->mouse_move)
		{
			g->mouse_move = 0;
			g->key_rotate = -1;
		}
		g->turn_direction = 1;
		g->rot = g->rot + g->turn_direction * (ROTSPEED * 180 / M_PI);
		aux_dirx = g->dir.x;
		g->dir.x = g->dir.x * cos(ROTSPEED) - g->dir.y * sin(ROTSPEED);
		g->dir.y = aux_dirx * sin(ROTSPEED) + g->dir.y * cos(ROTSPEED);
		aux_planex = g->plane.x;
		g->plane.x = g->plane.x * cos(ROTSPEED) - g->plane.y * sin(ROTSPEED);
		g->plane.y = aux_planex * sin(ROTSPEED)
			+ g->plane.y * cos(ROTSPEED);
	}
}

void	ft_move_shape(t_game *g)
{
	if (g->key_move == 13
		|| g->key_move == 1)
		ft_move_back_and_forth(g, g->key_move);
	if (g->key_sides == 2
		|| g->key_sides == 0)
		ft_move_sideways(g, g->key_sides);
	if (g->key_rotate == 123
		|| g->key_rotate == 124)
		ft_rot_left_right(g, g->key_rotate);
}
