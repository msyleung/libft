/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:49:06 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:51:56 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	void	*tmp;

	if (!(tmp = (void *)ft_memalloc(oldsize + newsize)))
		return (NULL);
	if (!ptr)
		ptr = malloc(newsize);
	else if (ptr && !oldsize)
		free(ptr);
	else if (!ptr && !oldsize)
		return (ptr);
	else
	{
		if (newsize > oldsize)
			newsize = oldsize;
		tmp = ft_memcpy(tmp, ptr, newsize);
		ft_memdel(&ptr);
	}
	return (tmp);
}
