/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:56:15 by jpiniau           #+#    #+#             */
/*   Updated: 2014/11/19 11:48:37 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	i = -1;
	new_str = NULL;
	if (s && f)
	{
		new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (new_str)
		{
			while (s[++i])
				new_str[i] = f(s[i]);
			new_str[i] = '\0';
		}
	}
	return (new_str);
}
