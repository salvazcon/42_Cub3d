/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:19:20 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/21 16:54:38 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == 53 && g)
		ft_destroy(g);
	if (keycode == 13 || keycode == 1)
		g->key_move = keycode;
	if (keycode == 2 || keycode == 0)
		g->key_sides = keycode;
	if (keycode == 124 || keycode == 123)
		g->key_rotate = keycode;
	return (0);
}

int	key_release(int keycode, t_game *g)
{
	if (keycode == 124 || keycode == 123)
	{
		g->turn_direction = 0;
		g->key_rotate = -1;
	}
	if (keycode == 13 || keycode == 1)
		g->key_move = -1;
	if (keycode == 2 || keycode == 0)
		g->key_sides = -1;
	return (0);
}

void	ft_parser(t_game *g, char *file)
{
	char	*aux;

	ft_check_ext(g, file);
	aux = ft_read_file(g, file);
	ft_break_file(g, aux);
	ft_check_data(g);
	ft_check_car(g);
	ft_check_edg(g);
	free(aux);
}

void	ft_game(t_game *g)
{
	ft_init_game(g);
	ft_raycast(g);
	mlx_hook(g->win, 17, 0, ft_destroy, g);
	mlx_hook(g->win, 2, 0, key_press, g);
	mlx_hook(g->win, 3, 0, key_release, g);
	mlx_loop_hook(g->mlx, &ft_raycast, g);
	mlx_loop(g->mlx);
}

int	main(int argv, char **argc)
{
	t_game	*g;

	if (argv != 2)
		return (perror("Error: Numero de argumentos invalidos."), 1);
	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (perror("Error: Fallo la resreva de memoria."), 1);
	g->mlx = mlx_init();
	ft_parser(g, argc[1]);
	ft_game(g);
	ft_destroy(g);
	return (0);
}

/* void	ft_leaks(void) //borrar
{
	system("leaks -q cub3d");
	atexit(ft_leaks); //borrar
} */