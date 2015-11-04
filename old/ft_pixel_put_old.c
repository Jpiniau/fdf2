/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:32:37 by jpiniau           #+#    #+#             */
/*   Updated: 2015/03/31 16:59:57 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

float	ft_high(t_line l, t_point p)
{
	float tmp;
	float x;

	l.x2 -= l.x1;
	l.y2 -= l.y1;
	x = (float)p.x - (float)l.x1; 
	tmp = ((float)l.y2 / (float)l.x2);
	tmp = ((tmp * x) * 10) / l.y2;
	//	printf("y2 = %d x2 = %d x = %F tmp = %F\n", l.y2, l.x2, x, tmp);
	return (tmp * 10);
}

int		couleur(double t)
{
	(void)t;
	//return ((RGB( 136 * (cos(t) + 1), 136 * (sin(t) + 1), 136 * (1 - cos(t))))); 
	if (t == 0)
		return ((RGB (136, 136, 136)));
	else
		return ((RGB (136 + t, 136 + t, 136 + t)));
} 

int		ft_pixel_put(t_env *e, t_point p, double z)
{
	//	long rgb;

	//	rgb = couleur(z);
	/*	e->data[(p.x * img.bpp / 8 ) + (p.y * img.sizeline)] = (rgb & 0xff0000 >> 16);
		e->data[(p.x * img.bpp / 8 ) + (p.y * img.sizeline) + 1] = (rgb & 0xff00 >> 8);
		e->data[(p.x * img.bpp / 8 ) + (p.y * img.sizeline) + 2] = (rgb & 0xff);
		e->data[(p.x * img.bpp / 8 ) + (p.y * img.sizeline) + 3] = 0;
		*/
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
