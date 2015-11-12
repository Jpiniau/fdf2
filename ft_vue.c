/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:53:18 by jpiniau           #+#    #+#             */
/*   Updated: 2015/11/12 14:33:47 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static int		ft_countspc(char *tmp)
{
	int i;

	i = 0;
	while (*tmp != '\0')
	{
		if (*tmp == ' ')
			i++;
		tmp++;
	}
	return (i);
}

static int		ft_count(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

static t_point	**ft_iso(char **matrix, int nb_line, t_point p, int ech)
{
	t_point	**new_matrix;
	char	**tmp;
	int		y;
	int		x;
	int		z;

	y = -1;
	x = -1;
	new_matrix = (t_point **)malloc(sizeof(t_point*) * nb_line);
	while (++y < nb_line)
	{
		tmp = ft_strsplit(matrix[y], ' ');
		new_matrix[y] = (t_point *)malloc(sizeof(t_point) * ft_count(tmp));
		while (tmp[++x])
		{
			z = (ft_atoi(tmp[x]) != 0 ? ft_atoi(tmp[x]) * p.z : 0);
			new_matrix[y][x].x = (int)((x * ech + TLE) * CTE) + 500;
			new_matrix[y][x].x -= ((y * ech + TLE) * CTE + 450 - p.x);
			new_matrix[y][x].y = (int)(-z + ((CTE / 2) * (x * ech + TLE)));
			new_matrix[y][x].y += (((CTE / 2) * (y * ech + TLE)) + p.y);
			new_matrix[y][x].z = z;
		}
		x = -1;
	}
	return (new_matrix);
}

static t_point	**ft_parallele(char **matrix, int nb_line, t_point p, int echel)
{
	t_point	**new_matrix;
	char	**tmp;
	int		y;
	int		x;
	int		z;

	y = -1;
	x = -1;
	new_matrix = (t_point **)malloc(sizeof(t_point*) * nb_line);
	while (++y < nb_line)
	{
		tmp = ft_strsplit(matrix[y], ' ');
		new_matrix[y] = (t_point *)malloc(sizeof(t_point) * ft_count(tmp));
		while (tmp[++x])
		{
			z = (ft_atoi(tmp[x]) != 0 ? ft_atoi(tmp[x]) * p.z : 0);
			new_matrix[y][x].x = (int)((x * echel + TLE));
			new_matrix[y][x].x += CTE * z * 2 + p.x;
			new_matrix[y][x].y = (int)((y * echel + TLE));
			new_matrix[y][x].y += ((CTE / 2) * -(z) * 2 + p.y);
			new_matrix[y][x].z = z;
		}
		x = -1;
	}
	return (new_matrix);
}

t_matrix		ft_vue(char **mat, int nb_line, t_point p)
{
	t_matrix	matrix;
	int			width_mat;
	int			echelle;
	int			tmp;

	width_mat = ft_countspc(mat[0]);
	tmp = WIN_HEIGHT < WIN_WIDTH ? WIN_HEIGHT : WIN_WIDTH;
	if (width_mat > nb_line)
		echelle = tmp / (width_mat + p.zo);
	else
		echelle = tmp / (nb_line + p.zo);
	matrix.iso = ft_iso(mat, nb_line, p, echelle);
	matrix.par = ft_parallele(mat, nb_line, p, echelle);
	return (matrix);
}
