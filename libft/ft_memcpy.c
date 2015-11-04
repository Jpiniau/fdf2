/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:30:51 by jpiniau           #+#    #+#             */
/*   Updated: 2015/10/08 15:22:46 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*sr;
	char	*ds;

	sr = (char*)src;
	ds = (char *)dst;
	while (n--)
		*ds++ = *sr++;
	return (dst);
}
