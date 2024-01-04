/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:19:20 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 13:09:28 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	ft_check_data()
{
	//compribar que exista el arhivo de los exprits y convertirlos en void
	//compribar que los colores sean correctos
} */

void	ft_init_data(t_game *g, char *file)
{
	int i;
	
	i = -1;
	ft_check_ext(g, file);
	ft_break_file(g, ft_read_file(g, file));
	/*printf("---------------------------\n");
	printf("Esto es el mapa desglosado:\n");
	printf("---------------------------\n");
	printf("%s\n", g->map); */
	ft_check_map(g);
/* 	printf("---------------------------\n");
	printf("Esto es el mapa checkeado:\n");
	printf("---------------------------\n");
	printf("%s\n", g->map); */
	/* ft_check_data(g); */
}

int main(int argv, char **argc)
{

	t_game	*g;

	if (argv != 2)
		return (1); //mejorable??
	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (1); //mejorable??
	ft_init_data(g, argc[1]);
	/*
	g->mlx = mlx_init();
	ft_init();
	mlx_key_hook();
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free_all(d);
	*/
	return(0);
}