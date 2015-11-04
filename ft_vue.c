/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:53:18 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/28 18:00:19 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static int		ft_count(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

static t_point	**ft_iso(char **matrix, int nb_line, t_point p)
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
			z = (ft_atoi(tmp[x]) > 0 ? ft_atoi(tmp[x]) + p.z : 0);
			new_matrix[y][x].x = (int)((x * DCL + TLE) * CTEISO1);
			new_matrix[y][x].x -= ((y * DCL + TLE) * CTEISO2 + 450 + p.x);
			new_matrix[y][x].y = (int)(-z + ((CTEISO1 / 2) * (x * DCL + TLE)));
			new_matrix[y][x].y += (((CTEISO2 / 2) * (y * DCL + TLE)) + p.y);
			new_matrix[y][x].z = z;
		}
		x = -1;
	}
	return (new_matrix);
}

static t_point	**ft_parallele(char **matrix, int nb_line, t_point p)
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
			z = (ft_atoi(tmp[x]) > 0 ? ft_atoi(tmp[x]) + p.z : 0);
			new_matrix[y][x].x = (int)((x * DCL + TLE) + CTE * z * 2 + p.x);
			new_matrix[y][x].y = (int)((y * DCL + TLE));
			new_matrix[y][x].y += ((CTE / 2) * -(z) * 2 + p.y);
			new_matrix[y][x].z = z;
		}
		x = -1;
	}
	return (new_matrix);
}

t_matrix		ft_vue(char **mat, int nb_line, t_point p)
{
	t_matrix matrix;

	matrix.par = ft_parallele(mat, nb_line, p);
	matrix.iso = ft_iso(mat, nb_line, p);
	return (matrix);
}