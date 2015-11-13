/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 11:51:35 by jpiniau           #+#    #+#             */
/*   Updated: 2015/11/13 18:35:21 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "mlx.h"
# include <stdlib.h>
# include <math.h>

# define WIN_HEIGHT (2000)
# define WIN_WIDTH (1300)
# define CTE (0.9)
# define CTEI1 (0.9)
# define CTEI2 (0.9)
# define TLE (25)
# define DCL (25)
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

# define ANGLE (0)
# define HAUTEUR (1)
# define ECHAP (53)
# define SPACE (49)
# define RIGHT (124)
# define LEFT (123)
# define UP (126)
# define DOWN (125)
# define MINUS (27)
# define PLUS (24)
# define W (13)
# define A (0)
# define S (1)
# define D (2)
# define R (15)
# define I (34)
# define P (35)
# define Z (6)
# define X (7)
# define M (46)
# define H (4)
# define NUM_0 (48)
# define NUM_1 (49)
# define NUMPAD_PLUS (78)
# define NUMPAD_MINUS (69)
# define NUMPAD_0 (82)
# define NUMPAD_1 (83)
# define NUMPAD_2 (84)
# define NUMPAD_3 (85)
# define NUMPAD_4 (86)
# define NUMPAD_5 (87)
# define NUMPAD_6 (88)
# define NUMPAD_7 (89)
# define NUMPAD_8 (91)
# define NUMPAD_9 (92)

typedef struct	s_img
{
	int			bpp;
	int			sizeline;
	int			endian;
}				t_img;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			zo;
}				t_point;

typedef struct	s_matrix
{
	char		*def;
	t_point		**par;
	t_point		**iso;
	t_point		**con;
}				t_matrix;

typedef struct	s_size
{
	size_t		width;
	size_t		height;
}				t_size;

typedef struct	s_env
{
	char		*name;
	void		*mlx;
	void		*win;
	void		*im;
	t_img		img;
	char		*data;
	t_matrix	matrix;
	size_t		width_mat;
	size_t		height_mat;
	t_size		size_mat;
}				t_env;

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			z1;
	int			z2;
}				t_line;

typedef struct	s_dir
{
	int			x;
	int			y;
}				t_dir;

void			fdf(t_env e, int i, int m);
char			*create_matrix(char *line, int index);
int				check_matrix(char *tmp_mat, int nb_line, t_env *e);
t_point			set_point(void);
void			transform(char *tmp_matrix, int nb_line, t_point p, t_env *e);
t_matrix		ft_vue(char **mat, int nb_line, t_point p);
int				ft_collect(t_point **matrix, t_env *e, t_size size);
int				ft_line(t_env *e, t_line l);
int				ft_pixel_put(t_env *e, t_point p, double z);
void			action(t_env env, int action);
t_line			ft_switch(t_line l);
int				ft_menu(t_env *e);

#endif
