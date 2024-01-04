/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:19:33 by saazcon-          #+#    #+#             */
/*   Updated: 2024/01/04 18:58:39 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <stdio.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <stddef.h>
# include <dirent.h>
# include <sys/time.h>
# include <pthread.h>
# include <mlx.h> //minilib x

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*n;
	char	*s;
	char	*w;
	char	*e;
	char	*f;
	char	*c;
	int		row;
	char	*map;
	char	**data;
}	t_game;

void	ft_check_wesn(t_game *g, char letter, int i, int j);
void	ft_check_cf(t_game *g, char letter, int i, int j);
void	ft_error(t_game *g, char *error, int num);
void	*ft_calloc(size_t count, size_t size);
void	ft_break_file(t_game *g, char *file);
void	ft_check_ext(t_game *g, char *file);
void	ft_free_double(char **str);
void	ft_check_data(t_game *g);
void	ft_check_map(t_game *g);
void	ft_free(t_game *g);
char	*ft_substr(char *s, unsigned int start, int len);
char	**ft_split_n(const char *s, char c, int n);
char	*ft_strjoin_gnl(char *stash, char *buff);
char	*ft_read_file(t_game *g, char *file);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
int		ft_strchr(char *s, int c);
int		ft_row_size(char *map);
int		ft_atoi(char *str);

#endif
