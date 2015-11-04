/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 14:58:01 by jpiniau           #+#    #+#             */
/*   Updated: 2015/03/31 16:09:25 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	check_matrix(char *tmp_mat, int nb_line, t_env *e)
{
	char	**tmp;
	char	**matrix;
	int		y;
	int		x;
	size_t	tmpw;

	matrix = ft_strsplit(tmp_mat, '\n');
	y = -1;
	e->size_mat.height = 0;
	while (++y < nb_line)
	{
		e->size_mat.height++;
		e->size_mat.width = 0;
		x = -1;
		tmp = ft_strsplit(matrix[y], ' ');
		while (tmp[++x])
		{
			e->size_mat.width++;
		}
		if (y >= 1)
			if (tmpw != e->size_mat.width)
				return (1);
		tmpw = e->size_mat.width;
	}
	return (0);
}
