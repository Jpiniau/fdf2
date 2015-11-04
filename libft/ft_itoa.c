/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:45:08 by jpiniau           #+#    #+#             */
/*   Updated: 2015/01/15 19:34:14 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_size(int n)
{
	int i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_fill(char *str, int n, int i)
{
	int j;
	int size;

	size = i;
	j = 0;
	if (n < 0)
	{
		str[j++] = '-';
		n = -n;
	}
	while (i > j)
	{
		if (str[i--] != '-')
			str[i] = '0' + (n % 10);
		n /= 10;
	}
	str[size] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char *str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * ft_size(n) + 1);
	if (str)
	{
		if (n == -2147483648)
			str = ft_strcpy(str, "-2147483648");
		else
			str = ft_fill(str, n, ft_size(n));
	}
	return (str);
}
