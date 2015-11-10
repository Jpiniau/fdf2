/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 15:27:12 by jpiniau           #+#    #+#             */
/*   Updated: 2015/11/10 18:31:50 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	transform(char *tmp_matrix, int nb_line, t_point p, t_env *e)
{
	char		**mat;
	t_matrix	matrix;

	mat = ft_strsplit(tmp_matrix, '\n');
	matrix = ft_vue(mat, nb_line, p);
	matrix.def = tmp_matrix;
	e->matrix = matrix;
}
