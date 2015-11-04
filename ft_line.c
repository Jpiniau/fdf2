/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:40:16 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/28 17:43:06 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int		ft_draw_oct1(t_env *e, t_line l, t_dir d)
{
	int		incest;
	int		incnordest;
	int		error;
	t_point	p;

	p.x = l.x1;
	p.y = l.y1;
	incest = 2 * d.y;
	incnordest = 2 * (d.y - d.x);
	error = 2 * d.y - d.x;
	while (p.x <= l.x2)
	{
		ft_pixel_put(e, p, 0);
		if (error >= 0)
		{
			p.y++;
			error += incnordest;
		}
		else
			error += incest;
		p.x++;
	}
	return (0);
}

static int		ft_draw_oct2(t_env *e, t_line l, t_dir d)
{
	int		incest;
	int		incnordest;
	int		error;
	t_point	p;

	p.x = l.x1;
	p.y = l.y1;
	incest = 2 * d.x;
	incnordest = 2 * (d.x - d.y);
	error = 2 * d.x - d.y;
	while (p.y <= l.y2)
	{
		ft_pixel_put(e, p, 0);
		if (error >= 0)
		{
			p.x++;
			error += incnordest;
		}
		else
			error += incest;
		p.y++;
	}
	return (0);
}

static int		ft_draw_oct1_inv(t_env *e, t_line l, t_dir d)
{
	int		incest;
	int		incsudest;
	int		error;
	t_point	p;

	p.x = l.x1;
	p.y = l.y1;
	d.y = ((d.y >= 0) ? d.y : -d.y);
	incest = 2 * d.y;
	incsudest = 2 * (d.y - d.x);
	error = 2 * d.y - d.x;
	while (p.x <= l.x2)
	{
		ft_pixel_put(e, p, 0);
		if (error >= 0)
		{
			p.y--;
			error += incsudest;
		}
		else
			error += incest;
		p.x++;
	}
	return (0);
}

static int		ft_draw_oct2_inv(t_env *e, t_line l, t_dir d)
{
	int		incest;
	int		incsudest;
	int		error;
	t_point	p;

	p.x = l.x1;
	p.y = l.y1;
	d.y = ((d.y >= 0) ? d.y : -d.y);
	incest = 2 * d.x;
	incsudest = 2 * (d.x - d.y);
	error = 2 * d.x - d.y;
	while (p.y >= l.y2)
	{
		ft_pixel_put(e, p, 0);
		if (error >= 0)
		{
			p.x++;
			error += incsudest;
		}
		else
			error += incest;
		p.y--;
	}
	return (0);
}

int				ft_line(t_env *e, t_line l)
{
	t_dir d;

	l = (l.x1 > l.x2 ? ft_switch(l) : l);
	d.x = l.x2 - l.x1;
	d.y = l.y2 - l.y1;
	if (d.x > d.y)
	{
		if (l.y1 <= l.y2)
			ft_draw_oct1(e, l, d);
		else
		{
			if ((l.y2 - l.y1) < (l.x1 - l.x2))
				ft_draw_oct2_inv(e, l, d);
			else
				ft_draw_oct1_inv(e, l, d);
		}
	}
	else
	{
		if (l.y1 <= l.y2)
			ft_draw_oct2(e, l, d);
		else
			ft_draw_oct2_inv(e, l, d);
	}
	return (0);
}
