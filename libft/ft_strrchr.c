/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:33:36 by jpiniau           #+#    #+#             */
/*   Updated: 2014/11/05 18:37:19 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lst;

	lst = NULL;
	if (*s == (char)c)
		lst = (char*)s;
	while (*s++ != '\0')
		if (*s == (char)c)
			lst = (char*)s;
	return (lst);
}
