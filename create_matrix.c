/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 16:31:29 by jpiniau           #+#    #+#             */
/*   Updated: 2015/11/04 17:52:27 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

char	*create_matrix(char *line, int index)
{
	static char		*tmp;
	static size_t	len_verif;
	size_t			len_line;
	size_t			len_tmp;

	len_line = ft_strlen(line);
	if (tmp == NULL)
	{
		if (!(tmp = (char *)ft_memalloc(sizeof(char) * len_line + 1)))
		{
			ft_putstr_fd("Error malloc !!", 2);
			return (NULL);
		}
	}
	len_tmp = ft_strlen(tmp) + 1;
	if (!(tmp = (char *)ft_realloc(tmp, len_tmp + len_line + 1)))
	{
		ft_putstr_fd("Error malloc !!", 2);
		return (NULL);
	}
	if (index == 0)
		len_verif = len_line;
	tmp[len_tmp - 1] = '\n';
	tmp[len_tmp + len_line] = '\0';
	ft_putchar('\n');
	ft_putstr("line:\n");
//	ft_putchar('\n');
//	ft_putnbr(len_line);
//	ft_putchar('\n');
	ft_putstr(line);
	ft_putstr("\n");
	ft_strcat(tmp, line);
	ft_putstr("tmp:\n");
	ft_putstr(tmp);
	return (tmp);
}
