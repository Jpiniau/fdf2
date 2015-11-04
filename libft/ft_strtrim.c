/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:00:39 by jpiniau           #+#    #+#             */
/*   Updated: 2014/11/10 19:19:21 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*str_trim;
	size_t	size_trim;

	if (s == NULL)
		return (NULL);
	while (is_whitespace(*s) && *s != '\0')
		s++;
	size_trim = ft_strlen(s);
	while (is_whitespace(s[size_trim - 1]) && size_trim != 0)
		size_trim--;
	str_trim = (char *)malloc(sizeof(char) * size_trim);
	if (str_trim != NULL)
	{
		ft_strncpy(str_trim, s, size_trim);
		str_trim[size_trim] = '\0';
	}
	return (str_trim);
}
