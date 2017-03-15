/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tonarrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:58:25 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:54:22 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	convert_unicode(wchar_t c, char *dst, int j)
{
	if (c < (1 << 7))
		dst[j++] = c;
	else if (c < (1 << 11))
	{
		dst[j++] = ((c >> 6) + 0xC0);
		dst[j++] = ((c & 0x3F) + 0x80);
	}
	else if (c < (1 << 16))
	{
		dst[j++] = ((c >> 12) + 0xE0);
		dst[j++] = (((c >> 6) & 0x3F) + 0x80);
		dst[j++] = ((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		dst[j++] = ((c >> 18) + 0xF0);
		dst[j++] = (((c >> 12) & 0x3F) + 0x80);
		dst[j++] = (((c >> 6) & 0x3F) + 0x80);
		dst[j++] = ((c & 0x3F) + 0x80);
	}
	return (j);
}

int			ft_tonarrow(wchar_t *str, char *dst, int dlen, t_struct *d)
{
	int		i;
	int		j;
	wchar_t	c;

	j = ft_strlen(dst);
	i = 0;
	if (d->conv == 'S' && d->p != 0)
		dlen = d->p + j;
	while (str[i] != 0 && j < dlen - 1)
	{
		c = str[i];
		j = convert_unicode(c, dst, j);
		i++;
	}
	dst[j] = '\0';
	return (j);
}
