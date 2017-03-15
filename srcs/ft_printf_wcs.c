/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:59:16 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:44:00 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_widelen(wchar_t c)
{
	if (c < (1 << 7))
		return (2);
	else if (c < (1 << 11))
		return (2);
	else if (c < (1 << 16))
		return (3);
	else if (c < (1 << 21))
		return (4);
	return (0);
}

int			ft_printf_wc(wchar_t c, t_struct *d)
{
	char	*tmp;
	int		spaces;
	int		len;
	int		ti;

	ti = 0;
	if (!c)
		write_null(d);
	len = (d->mw > 4) ? d->mw : ft_widelen(c);
	tmp = ft_strnew(len);
	spaces = d->mw - ft_widelen(c);
	if (d->minus == 0 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	ti += ft_tonarrow(&c, tmp, len, d);
	if (d->minus == 1 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	tmp[ti] = 0;
	len = ft_putstrcount(tmp);
	if (c == 0)
		len += 1;
	ft_strdel(&tmp);
	return (len);
}

int			ft_printf_ws(wchar_t *str, t_struct *d, int len, int ti)
{
	char	*tmp;
	int		zero;
	int		si;

	si = -1;
	if (!str || d->p == -1)
		return (write_null(d));
	while (str[++si] != '\0')
		len += ft_widelen(str[si]);
	tmp = ft_strnew(len + d->mw);
	si = count_spaces(d, len);
	if (d->minus == 0 && si > 0 && !d->zero)
		ti = write_spaces(si, tmp, ti);
	else if ((zero = d->mw - len) > 0 && d->zero)
		ti = write_zeros(zero, tmp, ti);
	ti += ft_tonarrow(str, tmp, len + d->mw, d);
	if (d->minus == 1 && si > 0)
		ti = write_spaces(si, tmp, ti);
	if (d->minus)
		tmp[ti] = 0;
	len = ft_putstrcount(tmp);
	ft_strdel(&tmp);
	return (len);
}
