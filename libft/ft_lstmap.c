/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 18:55:52 by jpiniau           #+#    #+#             */
/*   Updated: 2015/05/23 19:42:20 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = NULL;
	if (lst && f)
	{
		while (lst)
		{
			tmp = f(lst);
			ft_lstaddback(&new_lst, ft_lstnew(tmp->content, tmp->content_size));
			lst = lst->next;
		}
	}
	return (new_lst);
}
