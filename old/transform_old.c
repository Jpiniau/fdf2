/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 15:27:12 by jpiniau           #+#    #+#             */
/*   Updated: 2015/03/31 17:04:45 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

void		affic(t_point **mat, int h, int w)
{
	int	i;
	int j;

	i = -1;
	j = 0;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			ft_putchar('(');
			ft_putnbr(mat[i][j].x);
			ft_putchar(' ');
			ft_putnbr(mat[i][j].y);
			ft_putchar(' ');
			ft_putnbr(mat[i][j].z);
			ft_putchar(')');
			ft_putchar(',');
		}
		ft_putchar('\n');
	}
}

t_matrix	transform(char *tmp_matrix, int nb_line, t_point p)
{
	char		**mat;
	t_matrix	matrix;

	mat = ft_strsplit(tmp_matrix, '\n');
	matrix.par = ft_parallele(mat, nb_line, p);
	matrix.iso = ft_iso(mat, nb_line, p);
	matrix.def = tmp_matrix;
//	affic(matrix.par, height, width);
	return (matrix);
}
