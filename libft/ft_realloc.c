/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:37:25 by jpiniau           #+#    #+#             */
/*   Updated: 2015/10/30 14:34:40 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ptr2;

	ptr2 = ft_memalloc(size);
	ft_memcpy(ptr2, ptr, size);;
	ptr = NULL;
	return (ptr2);
}
