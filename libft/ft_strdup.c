/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:14:23 by jpiniau           #+#    #+#             */
/*   Updated: 2015/10/08 15:23:30 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	if (!s1)
		return (NULL);
	cpy = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!cpy)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
