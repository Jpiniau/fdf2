/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:03:24 by jpiniau           #+#    #+#             */
/*   Updated: 2014/11/24 15:52:02 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxtlst;

	lst = NULL;
	if (alst && *alst && del)
	{
		lst = *alst;
		while (lst != NULL)
		{
			nxtlst = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = nxtlst;
		}
		*alst = NULL;
	}
}
