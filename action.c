/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 16:00:27 by jpiniau           #+#    #+#             */
/*   Updated: 2015/11/12 15:11:10 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

static int		ft_z(int z, int c)
{
	float	new_z;
	float	tmp;

	tmp = 0.0;
	if (c == 125 && z == 1)
		return (-1);
	if (c == 126 && z == -1)
		return (1);
	if ((c == 126 && z >= 0) || (c == 125 && z < 0))
		tmp = z * 1.5;
	else if ((c == 126 && z <= 0) || (c == 125 && z > 0))
		tmp = z / 1.5;
	if (tmp > 0)
		new_z = tmp - (int)tmp;
	else
		new_z = -tmp + (int)tmp;
	if (new_z >= 0.5 && tmp > 0)
		new_z = (int)tmp + 1;
	else if (new_z >= 0.5 && tmp < 0)
		new_z = (int)tmp - 1;
	else
		new_z = (int)tmp;
	return ((int)new_z);
}

static void		apply(t_env save, t_point p, int i)
{
	transform(save.matrix.def, save.size_mat.height, p, &save);
	mlx_destroy_image(save.mlx, save.im);
	save.im = mlx_new_image(save.mlx, WIN_HEIGHT, WIN_WIDTH);
	fdf(save, i);
}

static t_point	switch_case(int action, t_point p, int *i)
{
	
	p.y = action == S ? p.y + 10 : p.y;
	p.y = action == W ? p.y - 10 : p.y;
	p.x = action == D ? p.x + 10 : p.x;
	p.x = action == A ? p.x - 10 : p.y;
	p.zo = action == Z ? p.y - 1 : p.y;
	p.zo = action == X ? p.y + 1 : p.y;
	else if (action == Z && p.zo > -9)
		p.zo -= 1;
	else if (action == X && p.zo < 12)
		p.zo += 1;
	else if (action == 126 && p.z < 7)
		p.z = ft_z(p.z, action);
	else if (action == 125 && p.z > -7)
		p.z = ft_z(p.z, action);
	else if (action == P)
		*i = 0;
	else if (action == I)
		*i = 1;
	else if (action == R)
	{
		p.x = 0;
		p.y = 0;
		p.z = 1;
		p.zo = 0;
	}
	return (p);
}

void			action(t_env env, int action)
{
	static t_env	save;
	static t_point	p;
	static int		appel;
	static int		i;

	if (appel != 1)
	{
		p.x = 0;
		p.y = 0;
		p.z = 1;
		p.zo = 0;
		i = 0;
		appel = 1;
	}
	if (action == 666)
		save = env;
	else
	{
		p = switch_case(action, p, &i);
		apply(save, p, i);
	}
}
