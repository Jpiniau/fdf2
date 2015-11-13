/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:23:19 by jpiniau           #+#    #+#             */
/*   Updated: 2015/11/13 18:55:36 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"

static int		ft_key_hook(int keycode)
{
	t_env	e;

	ft_putnbr(keycode);
	if (keycode == ECHAP)
		exit(0);
	else
		action(e, keycode);
	return (0);
}

static t_env	ft_get_data(t_env *e)
{
	int		bpp;
	int		sizeline;
	int		endian;

	e->data = mlx_get_data_addr(e->im, &bpp, &sizeline, &endian);
	e->img.bpp = bpp;
	e->img.sizeline = sizeline;
	e->img.endian = endian;
	return (*e);
}

void			fdf(t_env e, int i, int m)
{
	e = ft_get_data(&e);
	if (i == 0)
		ft_collect(e.matrix.par, &e, e.size_mat);
	else if (i == 1)
		ft_collect(e.matrix.iso, &e, e.size_mat);
	mlx_string_put(e.mlx, e.win, 800, 50, 0xffffff, "TEST");
	mlx_put_image_to_window(e.mlx, e.win, e.im, 0, 0);
	action(e, 666);
	mlx_hook(e.win, 2, 4, ft_key_hook, &e);
//	if (m)
	(void)m;
	//	mlx_loop_hook(e.mlx, &ft_menu, &e);
	mlx_loop(e.mlx);
	mlx_expose_hook(e.win, ft_key_hook, &e);
	mlx_destroy_image(e.mlx, e.im);
	mlx_destroy_window(e.mlx, e.win);
}

int				main(int ac, char **av)
{
	int			fd;
	int			index;
	char		*line;
	char		*tmp;
	t_env		e;

	if (ac <= 1)
		return (0);
	index = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!(tmp = create_matrix(line, index++)))
			return (0);
	}
	close(fd);
	if (check_matrix(tmp, index, &e))
		return (-1);
	transform(tmp, index, set_point(), &e);
	e.mlx = mlx_init();
	e.name = av[1];
	e.win = mlx_new_window(e.mlx, WIN_HEIGHT, WIN_WIDTH, e.name);
	e.im = mlx_new_image(e.mlx, WIN_HEIGHT, WIN_WIDTH);
	fdf(e, 0, 0);
	return (0);
}
