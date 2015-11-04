/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:59:42 by jpiniau           #+#    #+#             */
/*   Updated: 2014/11/16 14:18:10 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = NULL;
	lst = (t_list *)malloc(sizeof(t_list));
	if (lst)
	{
		if (content != NULL)
		{
			lst->content = (void *)malloc(content_size);
			if (lst->content)
			{
				lst->content = ft_memcpy(lst->content, content, content_size);
				lst->content_size = content_size;
				lst->next = NULL;
			}
		}
		else
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
	}
	return (lst);
}
