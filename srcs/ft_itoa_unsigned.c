/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:18:36 by sleung            #+#    #+#             */
/*   Updated: 2017/03/06 13:42:25 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_itoa_base_uns_long_length(uintmax_t value, int base)
{
	int	len;

	len = 0;
	while (value >= (uintmax_t)base)
	{
		value /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base_uns_long(uintmax_t value, int base)
{
	int		len;
	int		count;
	char	*str;

	count = 0;
	len = ft_itoa_base_uns_long_length(value, base);
	str = ft_strnew(len + 1);
	while (count <= len)
	{
		str[len - count] = "0123456789ABCDEF"[value % base];
		value /= base;
		count++;
	}
	str[len + 1] = '\0';
	return (str);
}
