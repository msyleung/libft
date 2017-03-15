/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:11:48 by sleung            #+#    #+#             */
/*   Updated: 2016/12/05 13:05:41 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cs1;
	char	*cs2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*cs1 != *cs2)
			return ((unsigned char)*cs1 - (unsigned char)*cs2);
		cs1++;
		cs2++;
		n--;
	}
	return (0);
}
