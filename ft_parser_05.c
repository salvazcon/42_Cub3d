/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_05.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:00:32 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/20 20:53:03 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	*ft_check_num(t_game *g, char **num)
{
	unsigned int	*n;
	int				i;

	i = -1;
	n = calloc(sizeof(int), 4);
	if (!n)
	{
		ft_free_double(num);
		ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
	}
	while (num[++i])
	{
		n[i] = ft_atoi(num[i]);
		if (n[i] < 0 || n[i] > 255)
		{
			free(n);
			ft_free_double(num);
			ft_error(g, "ERROR\n -> Color invalido.\n", 1);
		}
	}
	ft_free_double(num);
	return (n);
}

unsigned int	ft_init_color(t_game *g, unsigned int *num)
{
	unsigned int	color;

	color = 0;
	if (!num)
		return (0);
	color = (num[0] << 16) | (num[1] << 8) | num[2];
	if (color > 16777215)
	{
		free (num);
		ft_error(g, "ERROR\n -> Color invalido.\n", 1);
	}
	return (color);
}

void	ft_check_cf(t_game *g, char letter, int i, int j)
{
	unsigned int	*num;
	char			*aux;
	int				x;

	while (g->data[i][j] == ' ')
		j++;
	x = ft_strchr(g->data[i] + j, ' ');
	if (x == 0)
		while (g->data[i][x + j])
			x++;
	aux = ft_substr(g->data[i], j, x);
	num = ft_check_num(g, ft_split(aux, ','));
	free(aux);
	if (letter == 'C')
		g->c_color = ft_init_color(g, num);
	else
		g->f_color = ft_init_color(g, num);
	free(num);
}

t_addr	*ft_init_xpm(t_game *g, char *path)
{
	t_addr	*aux_addr;

	aux_addr = ft_calloc(1, sizeof(t_addr));
	if (!aux_addr)
	{
		free(path);
		ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
	}
	aux_addr->xpm = mlx_xpm_file_to_image(g->mlx, path, &g->mlx_x, &g->mlx_y);
	if (!aux_addr->xpm)
	{
		free(path);
		free(aux_addr);
		ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
	}
	aux_addr->mlx_addr = (int *)mlx_get_data_addr(aux_addr->xpm, \
	&aux_addr->bpp, &aux_addr->ll, &aux_addr->en);
	if (!aux_addr->mlx_addr)
	{
		free(path);
		ft_free_struct_addr(g, aux_addr);
		ft_error(g, "ERROR\n -> Problema inesperado.\n", 1);
	}
	return (aux_addr);
}

void	ft_check_wesn(t_game *g, char letter, int i, int j)
{
	char	*path;
	int		x;

	while (g->data[i][j] == ' ')
		j++;
	x = ft_strchr(g->data[i] + j, ' ');
	if (x == 0)
		while (g->data[i][x + j])
			x++;
	path = ft_substr(g->data[i], j, x);
	if (access(path, F_OK) != 0 || access(path, R_OK) != 0)
	{
		free(path);
		ft_error(g, "ERROR\n -> Archivo invalido.\n", 1);
	}
	if (letter == 'W')
		g->w_addr = ft_init_xpm(g, path);
	if (letter == 'E')
		g->e_addr = ft_init_xpm(g, path);
	if (letter == 'S')
		g->s_addr = ft_init_xpm(g, path);
	if (letter == 'N')
		g->n_addr = ft_init_xpm(g, path);
	free(path);
}
