/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 19:18:42 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/23 19:20:05 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **begin, t_list *new)
{
	if (begin != NULL)
	{
		if (*begin == NULL)
		{
			*begin = new;
		}
		else if ((*begin)->next == NULL)
			(*begin)->next = new;
		else
		{
			return (ft_lstaddback(&(*begin)->next, new));
		}
	}
}
