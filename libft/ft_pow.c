/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 18:16:27 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/21 18:19:39 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int x, int y)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	if (y == 0)
		return (1);
	else if (y < 0)
		return (0);
	while (i < y)
	{
		result *= x;
		i++;
	}
	return (result);
}
