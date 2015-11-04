/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 19:52:10 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/23 19:54:09 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *str, size_t n)
{
	char	*ptr;

	ptr = NULL;
	if (str != NULL)
	{
		ptr = (char *)malloc(sizeof(char) * n);
		if (ptr == NULL)
			return (NULL);
		ft_strncpy(ptr, str, n);
		ptr[n] = '\0';
	}
	return (ptr);
}
