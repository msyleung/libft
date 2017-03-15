/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:09:00 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:41:19 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*begin_fresh;

	if (lst)
	{
		fresh = (*f)(lst);
		begin_fresh = fresh;
		while (lst->next != NULL)
		{
			fresh->next = (*f)(lst->next);
			fresh = fresh->next;
			lst = lst->next;
		}
		fresh->next = NULL;
		return (begin_fresh);
	}
	return (NULL);
}
