/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:29:26 by jpiniau           #+#    #+#             */
/*   Updated: 2014/11/16 13:33:05 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	new_str = NULL;
	if (len == 0 && start == 0)
		return (ft_strdup(""));
	if (s)
	{
		while (start--)
			s++;
		new_str = (char *)malloc(len * sizeof(char));
		if (new_str != NULL)
		{
			ft_strncpy(new_str, s, len);
			new_str[len] = '\0';
		}
	}
	return (new_str);
}
