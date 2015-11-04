/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:31:21 by jpiniau           #+#    #+#             */
/*   Updated: 2014/11/19 11:46:07 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	i = -1;
	new_str = NULL;
	if (s && f)
	{
		new_str = (char *)malloc(sizeof(s));
		if (new_str)
		{
			while (s[++i])
				new_str[i] = f((unsigned int)i, s[i]);
			new_str[i] = '\0';
		}
	}
	return (new_str);
}
