/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:01:22 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 12:59:39 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if(g->mlx)
		free(g->mlx);
	if(g->win)
		free(g->win);
	if(g->map)
		free(g->map);
	if(g->data)
		ft_free_double(g->data);
}

void	ft_error(t_game *g, char *error, int num)
{
	perror(error);
	if (!g)
		ft_free_all(g);
	exit(num);
}