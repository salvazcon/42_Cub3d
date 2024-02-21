/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:01:22 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/20 18:57:48 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_struct_addr(t_game *g, t_addr *name)
{
	if (name->xpm)
		mlx_destroy_image(g->mlx, name->xpm);
	free(name);
}

void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_all(t_game *g)
{
	if (g->ln_map)
		free(g->ln_map);
	if (g->map)
		ft_free_double((char **)g->map);
	if (g->data)
		ft_free_double(g->data);
	if (g->s_addr)
		ft_free_struct_addr(g, g->s_addr);
	if (g->n_addr)
		ft_free_struct_addr(g, g->n_addr);
	if (g->w_addr)
		ft_free_struct_addr(g, g->w_addr);
	if (g->e_addr)
		ft_free_struct_addr(g, g->e_addr);
	if (g->img)
		mlx_destroy_image(g->mlx, g->img);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	free(g);
}

int	ft_destroy(t_game *g)
{
	if (g)
		ft_free_all(g);
	exit(0);
}

void	ft_error(t_game *g, char *error, int num)
{
	perror(error);
	if (g)
		ft_free_all(g);
	exit(num);
}
