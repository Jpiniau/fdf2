/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:32:37 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/28 17:46:12 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		ft_pixel_put(t_env *e, t_point p, double z)
{
	(void)z;
	if (p.x >= 0 && p.x < WIN_HEIGHT && p.y >= 0 && p.y < WIN_WIDTH)
	{
		e->data[(p.x * e->img.bpp / 8) + (p.y * e->img.sizeline)] = 0xff;
		e->data[(p.x * e->img.bpp / 8) + (p.y * e->img.sizeline) + 1] = 0xff;
		e->data[(p.x * e->img.bpp / 8) + (p.y * e->img.sizeline) + 2] = 0xff;
		e->data[(p.x * e->img.bpp / 8) + (p.y * e->img.sizeline) + 3] = 0;
	}
	return (0);
}
