/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 14:56:01 by jpiniau           #+#    #+#             */
/*   Updated: 2015/10/28 16:25:36 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void	*ft_realloc(void *ptr, size_t size)
{
	void	*ptr2;

	ptr2 = ft_memalloc(size);
	ft_memcpy(ptr2, ptr, size);
	ptr = NULL;
	return (ptr2);
}

static int	ft_fill_line(char **line, char **buf, int ret)
{
	int		n;

	if (ret == -1)
		*buf = NULL;
	if (ret == -1)
		return (-1);
	if (ret == 0 && *buf[0] == '\0')
	{
		*buf = NULL;
		*line = ft_strdup("\0");
		return (0);
	}
	n = ft_strcchr(*buf, '\n');
	if (n > -1)
	{
		*line = ft_strndup(*buf, n);
		*buf += n + 1;
		return (1);
	}
	else
	{
		*line = ft_strndup(*buf, ft_strlen(*buf));
		ft_strclr(*buf);
		return (1);
	}
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf[256];
	char		tmp[BUFF_SIZE + 1];
	int			is_n;
	int			ret;
	size_t		size;

	ret = 1;
	if (buf[fd] == NULL && line != NULL)
		buf[fd] = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	if (buf[fd] == NULL || fd < 0 || *line == NULL)
		return (-1);
	size = 1 + ft_strlen(buf[fd]);
	while ((is_n = ft_strcchr(buf[fd], '\n')) == -1 && ret > 0)
	{
		if ((ret = read(fd, tmp, BUFF_SIZE)))
		{
			tmp[ret] = '\0';
			size += BUFF_SIZE;
			if ((buf[fd] = (char *)ft_realloc(buf[fd], size)) == NULL)
				return (-1);
			ft_strcat(buf[fd], tmp);
		}
	}
	return (ft_fill_line(line, &buf[fd], ret));
}
