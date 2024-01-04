/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:19:20 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 18:57:47 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data(t_game *g, char *file)
{
	ft_check_ext(g, file);
	ft_break_file(g, ft_read_file(g, file));
	ft_check_map(g); //tiene una ft prezindible en ft_check.c
	ft_check_data(g);
}

int	main(int argv, char **argc)
{
	t_game	*g;

	if (argv != 2)
		return (1); //mejorable??
	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (1); //mejorable??
	ft_init_data(g, argc[1]);
	/* g->mlx = mlx_init();
	ft_init();
	mlx_key_hook();
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free_all(d);
	*/
	return (0);
}

/*printf("---------------------------\n");
	printf("Esto es el mapa desglosado:\n");
	printf("---------------------------\n");
	printf("%s\n", g->map);
	printf("---------------------------\n");
	printf("Esto es el mapa checkeado:\n");
	printf("---------------------------\n");
	printf("%s\n", g->map);
	printf("--------------------------\n");
	printf("N:%s\n", g->N);
	printf("S:%s\n", g->S);
	printf("W:%s\n", g->W);
	printf("E:%s\n", g->E);
	printf("F:%s\n", g->F);
	printf("C:%s\n", g->C);
	printf("--------------------------\n"); */