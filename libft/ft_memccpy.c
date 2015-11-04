/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:25:50 by jpiniau           #+#    #+#             */
/*   Updated: 2014/11/12 12:14:37 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*index;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	index = ft_memchr(src, (unsigned char)c, n);
	if (index == NULL)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	while (src++ <= index)
		*(d++) = *(s++);
	return (d);
}
