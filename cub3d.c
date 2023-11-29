/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:19:20 by saazcon-          #+#    #+#             */
/*   Updated: 2023/11/29 19:16:19 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_ext(t_game *g, char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] != '.' || file[i - 3] != 'c' \
	|| file[i - 2] != 'u' || file[i - 1] != 'b')
	{
		write(1, "ERROR\n -> Extension incorrecta, espabila bro!!\n", 31);
		ft_free(g);
		exit(1); //mejorable
	}
}

char	*ft_read(int fd)
{
	char	*buffer;
	char	*line;
	int		readed;

	line = ft_calloc(sizeof(char), 1);
	if (!line)
		return (NULL);
	buffer = ft_calloc(sizeof(char), 2);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read (fd, buffer, 1);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_read_file(t_game *g, char *file)
{
	char	*f;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "ERROR\n -> Problemas con archivo\n", 32);
		ft_free(g);
		exit(1); //mejorable
	}
	f = ft_read(fd);
	if (!f)
	{
		write(1, "ERROR\n -> Problemas con la lectura del archivo\n", 47);
		ft_free(g);
		exit(1); //mejorable
	}
	close(fd);
	return(f);
}

int		ft_ln_len(t_game *g) //por hacer!!
{
	i = -1
	len = 0;
	
	while(g->map[++i])
	{
		if(g->map[])
		i++;
		len++;
	}
}

void	ft_break_file(t_game *g, char *file)
{
	int		len;
	int		i;

	g->data = ft_split_n(file, '\n', 6);
	i = -1;
	len = 0;
	while (g->data[++i])
		len = ft_strlen(g->data[i]) + len;
	g->map = ft_substr(file, len, ft_strlen(file));
}

void	ft_flood_fill(t_game *g, int curl)
{
	if (g->map[curl] != '1' && g->map[curl] != '0' && g->map[curl] != 'F')
	{
		write(1, "ERROR\n -> El mapa es una mierda !\n", 34);
		ft_free(g);
		exit(1);
	}
	g->map[curl] = 'F';
	if (g->map[curl + 1] == '0')
		ft_flood_fill(g, curl + 1);
	if (g->map[curl - 1] == '0')
		ft_flood_fill(g, curl - 1);
	if (g->map[curl + /* num_file */] == '0')
		ft_flood_fill(g, curl + /* num_fila */);
	if (g->map[curl - /* num_fila */] == '0')
		ft_flood_fill(g, curl - /* num_fila */);
}
void	ft_check_map(t_game *g)
{
	int i;
	int c;
	int ln_len
	
	i = -1;
	c = 0;
	ln_len = ft_ln_len(g);
	while(g->map[++i])
	{
		if(g->map[i] == 0)
			ft_flood_fill(g->map, i);
		if(g->map[i] == 'N' || g->map[i] == 'S' || 
		g->map[i] == 'E' || g->map[i] == 'W')
		{
			c++;
			if (c > 1)
			{
				write(1, "ERROR\n -> Mas de un 'Play Start' fuiguara !\n", 44);
				ft_free(g);
				exit(1);  //mejorable y ademas necesario
			}	
		}
		if(g->map[i] != 'N' || g->map[i] != 'S' || g->map[i] != 'E'
		|| g->map[i] != 'W' || g->map[i] != 32 || g->map[i] != '\n')
		{
			write(1, "ERROR\n -> Caracter invalido en el mapa, maini !!\n", 49);
			ft_free(g);
			exit(1);  //mejorable y ademas necesario
		}
	}
	
}

void	ft_check_data()
{
	//compribar que exista el arhivo de los exprits y convertirlos en void
	//compribar que los colores sean correctos
}

/* void	*ft_check_file(char *file)
{

} */

void	ft_file(t_game *g, char file)
{
	char	*fl;

	ft_check_ext(g, file);
	ft_break_file(g, ft_read_file(g, file));
	ft_check_map(g);
	ft_check_data(g);
}

int main(int argv, char **argc)
{

	t_game	*g;

	if (argv != 2)
		return (1);
	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (1);
	ft_file(g, argc[1]);
	/* g->mlx = mlx_init();
	ft_init(); */
	//mlx_key_hook();
	//mlx_hook(d->win, 17, 0, ft_free, d);
	//mlx_loop(d->mlx);
	//ft_free(d);
	return(0);
}