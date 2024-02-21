/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:19:33 by saazcon-          #+#    #+#             */
/*   Updated: 2024/02/20 18:35:39 by saazcon-         ###   ########.fr       */
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
# include <math.h>
# include "./mlx/mlx.h"

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define MOVSPEED	0.08
# define ROTSPEED	0.05
# define X			0
# define Y			1

typedef struct s_addr
{
	void			*xpm;
	int				*mlx_addr;
	int				bpp;
	int				ll;
	int				en;
}	t_addr;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_game
{
	/* Game */
	void			*mlx;
	void			*win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			**data;
	char			*ln_map;
	t_addr			*s_addr;
	t_addr			*w_addr;
	t_addr			*e_addr;
	t_addr			*n_addr;
	unsigned int	c_color;
	unsigned int	f_color;
	int				**map;
	int				texx;
	int				texy;
	int				map_row;
	int				map_col;
	int				mlx_x;
	int				mlx_y;
	char			letter;
	/* Game */
	/* Math */
	t_vec			pos;
	t_vec			dir;
	t_vec			ray;
	t_vec			plane;
	double			rot;
	double			camera_x;
	int				key_move;
	int				key_rotate;
	int				key_sides;
	int				mouse_move;
	int				turn_direction;
		// -> DDA
	t_vec			side_dist;
	t_vec			delta_dist;
	double			perp_wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	/* Math */
}	t_game;

void			ft_check_wesn(t_game *g, char letter, int i, int j);
void			ft_check_cf(t_game *g, char letter, int i, int j);
void			ft_free_struct_addr(t_game *g, t_addr *name);
void			ft_error(t_game *g, char *error, int num);
void			*ft_calloc(size_t count, size_t size);
void			ft_break_file(t_game *g, char *file);
void			ft_check_ext(t_game *g, char *file);
void			ft_texture_loop(t_game *g, int x);
void			ft_draw_line(t_game *g, int x);
void			ft_free_double(char **str);
void			ft_check_data(t_game *g);
void			ft_move_shape(t_game *g);
void			ft_init_game(t_game *g);
void			ft_check_edg(t_game *g);
void			ft_check_car(t_game *g);
void			ft_free_all(t_game *g);
int				ft_raycast(void *param);
char			*ft_substr(char *s, unsigned int start, int len);
char			**ft_split_n(const char *s, char c, int n);
char			*ft_strjoin_gnl(char *stash, char *buff);
char			*ft_read_file(t_game *g, char *file);
char			**ft_split(char *s, char c);
char			*ft_strdup(char *s1);
int				ft_strchr(char *s, int c);
int				ft_row_size(char *map);
int				ft_destroy(t_game *g);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				ft_isdigit(int c);
unsigned int	ft_init_color(t_game *g, unsigned int *num);
t_addr			*ft_init_xpm(t_game *g, char *path);

#endif
