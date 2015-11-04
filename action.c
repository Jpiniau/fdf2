/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 16:00:27 by jpiniau           #+#    #+#             */
/*   Updated: 2015/11/04 17:36:29 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		apply(t_env save, t_point p, int i)
{
	save.matrix = transform(save.matrix.def, save.size_mat.height, p);
	mlx_destroy_image(save.mlx, save.im);
	save.im = mlx_new_image(save.mlx, WIN_HEIGHT, WIN_WIDTH);
	fdf(save, i);
}

static t_point	switch_case(int action, t_point p, int *i)
{
	if (action == W)
		p.y -= 10;
	else if (action == D)
		p.x += 10;
	else if (action == A)
		p.x -= 10;
	else if (action == S)
		p.y += 10;
	else if (action == 126)
		p.z = (p.z >= 50 ? p.z : p.z + 10);
	else if (action == 125)
		p.z = (p.z <= -50 ? p.z : p.z - 10);
	else if (action == P)
		*i = 0;
	else if (action == I)
		*i = 1;
	else if (action == R)
	{
		p.x = 0;
		p.y = 0;
		p.z = 0;
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
		p.z = 0;
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
