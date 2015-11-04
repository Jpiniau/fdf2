/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:25:48 by jpiniau           #+#    #+#             */
/*   Updated: 2014/12/12 14:42:24 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *d;

	if (s != 0)
	{
		d = (unsigned char*)s;
		while (n--)
			if (*d++ == (unsigned char)c)
				return ((void *)(d - 1));
	}
	return (NULL);
}
