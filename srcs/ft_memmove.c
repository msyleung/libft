/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:26:26 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:42:09 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*csrc;
	char	*cdst;
	char	*tmp;

	i = -1;
	if (len <= 0)
		return (dst);
	csrc = (char *)src;
	cdst = (char *)dst;
	tmp = (char *)malloc(sizeof(char) * len);
	if (tmp == NULL || len <= 0)
		return (dst);
	while (len > ++i)
		tmp[i] = csrc[i];
	i = -1;
	while (len > ++i)
		cdst[i] = tmp[i];
	free(tmp);
	return (dst);
}
