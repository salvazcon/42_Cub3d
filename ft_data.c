/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:00:32 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 18:56:49 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_num(t_game *g, char **num)
{
	int	i;
	int	n;

	i = -1;
	while (num[++i])
	{
		n = ft_atoi(num[i]);
		if (n < 0 || n > 255)
		{
			ft_free_double(num);
			ft_error(g, "ERROR\n -> Man, Ese color no existe !!\n", 1);
		}
	}
	ft_free_double(num);
}

void	ft_check_cf(t_game *g, char letter, int i, int j)
{
	char	*aux;
	int		x;

	while (g->data[i][j] == ' ')
		j++;
	x = ft_strchr(g->data[i] + j, ' ');
	if (x == 0)
		while (g->data[i][x + j])
			x++;
	aux = ft_substr(g->data[i], j, x);
	ft_check_num(g, ft_split(aux, ','));
	if (letter == 'C')
		g->c = ft_strdup(aux);
	else
		g->f = ft_strdup(aux);
	free(aux);
}

void	ft_check_wesn(t_game *g, char letter, int i, int j)
{
	char	*aux;
	int		x;

	while (g->data[i][j] == ' ')
		j++;
	x = ft_strchr(g->data[i] + j, ' ');
	if (x == 0)
		while (g->data[i][x + j])
			x++;
	aux = ft_substr(g->data[i], j, x);
	/* if (access(aux, F_OK) != 0)
	{
		free(aux);
		ft_error(g ,"ERROR\n -> Man, este file ni existe?? !!\n",1);
	} */ //No tocar , no tengo archivos todavia.
	if (letter == 'W')
		g->w = ft_strdup(aux);
	if (letter == 'E')
		g->e = ft_strdup(aux);
	if (letter == 'S')
		g->s = ft_strdup(aux);
	else
		g->n = ft_strdup(aux);
	free(aux);
}

void	ft_check_data(t_game *g)
{
	int	i;
	int	j;

	if (!g->data)
		ft_error(g, "ERROR\n -> lol, y los datos manin?? !!\n", 1);
	i = -1;
	while (g->data[++i])
	{
		j = 0;
		while (g->data[i][j] && g->data[i][j] == ' ')
			j++;
		if ((g->data[i][j]) && (g->data[i][j] == 'N' || g->data[i][j] == 'S' \
			|| g->data[i][j] == 'W' || g->data[i][j] == 'E'))
			ft_check_wesn(g, g->data[i][j], i, j + 2);
		else if ((g->data[i][j]) && (g->data[i][j] == 'F' \
			|| g->data[i][j] == 'C'))
			ft_check_cf(g, g->data[i][j], i, j + 1);
		else
			ft_error(g, "ERROR\n -> Estos dato que mierda son?? !!\n", 1);
	}
	if (i != 6)
		ft_error(g, "ERROR\n -> Faltan datos, al igual que neuronas!!\n", 1);
}
