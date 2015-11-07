/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 16:31:29 by jpiniau           #+#    #+#             */
/*   Updated: 2015/11/07 15:10:40 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

char	*create_matrix(char *line, int index)
{
	static char		*tmp;
	size_t			len_tmp;

	(void)index;
	if (tmp == NULL)
		tmp = ft_strnew(1);
	tmp = ft_strjoin(tmp, line);
	tmp = ft_strjoin(tmp, " ");
	len_tmp = ft_strlen(tmp);
	tmp[len_tmp - 1] = '\n';
	return (tmp);
}
