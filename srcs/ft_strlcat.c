/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:45:01 by sleung            #+#    #+#             */
/*   Updated: 2016/12/05 16:00:31 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*dstinit;

	i = 0;
	dstinit = dst;
	if (!size || size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (dst[i] != '\0')
		i++;
	while (size - 1 > i && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (ft_strlen(dstinit) + ft_strlen(src));
}
