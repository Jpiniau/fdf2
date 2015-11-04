/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:52:49 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/27 22:31:32 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static t_line	set_l(t_point tmp, int i)
{
	static t_line	l;

	if (i == 0)
	{
		l.x1 = tmp.x;
		l.y1 = tmp.y;
		l.z1 = tmp.z;
	}
	else
	{
		l.x2 = tmp.x;
		l.y2 = tmp.y;
		l.z2 = tmp.z;
	}
	return (l);
}

static void		horizontal(t_point **matrix, t_env *e, t_size size)
{
	t_line	l;
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < size.height)
	{
		j = -1;
		while (++j < size.width)
		{
			if ((j % 2) == 0)
				l = set_l(matrix[i][j], 0);
			else
				l = set_l(matrix[i][j], 1);
			if (j != 0)
				ft_line(e, l);
		}
	}
}

static void		vertical(t_point **matrix, t_env *e, t_size size)
{
	t_line	l;
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < size.height - 1)
	{
		j = -1;
		while (++j < size.width)
		{
			l = set_l(matrix[i][j], 0);
			l = set_l(matrix[i + 1][j], 1);
			ft_line(e, l);
		}
	}
}

int				ft_collect(t_point **matrix, t_env *e, t_size size)
{
	horizontal(matrix, e, size);
	vertical(matrix, e, size);
	return (0);
}
