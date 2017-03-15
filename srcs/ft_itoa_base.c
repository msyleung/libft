/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:22:31 by sleung            #+#    #+#             */
/*   Updated: 2017/03/06 13:40:57 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_itoa_base_length(intmax_t value, int base)
{
	int	len;

	len = (value < 0 && base == 10) ? 1 : 0;
	value = (value < 0 && base == 10) ? -value : value;
	while (value >= (intmax_t)base)
	{
		value /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(intmax_t value, int base)
{
	int		neg;
	int		len;
	int		count;
	char	*str;

	count = 0;
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_itoa_base_length(value, base);
	neg = (value < 0 && base == 10) ? 1 : 0;
	value = (value < 0 && base == 10) ? -value : value;
	str = ft_strnew(len + 1);
	while (count <= len)
	{
		str[len - count] = "0123456789ABCDEF"[value % base];
		value /= base;
		count++;
	}
	if (neg)
		str[0] = '-';
	str[len + 1] = '\0';
	return (str);
}
