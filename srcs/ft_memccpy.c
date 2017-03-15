/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:05:06 by sleung            #+#    #+#             */
/*   Updated: 2016/12/05 16:33:12 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*cdst;
	char	*csrc;

	csrc = (char *)src;
	cdst = (char *)dst;
	while (n > 0)
	{
		*cdst = *csrc;
		if (*csrc == c)
			return ((void *)(cdst + 1));
		cdst++;
		csrc++;
		n--;
	}
	return (NULL);
}
