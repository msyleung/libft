/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:55:33 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:42:54 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_c(unsigned char c, t_struct *d)
{
	char	*tmp;
	int		spaces;
	int		zero;
	int		len;
	int		ti;

	ti = 0;
	if (!c && !d->zero)
		return (write_null(d));
	len = (d->mw > 0) ? d->mw : 1;
	tmp = ft_strnew(len);
	spaces = (!d->zero) ? d->mw - 1 : 0;
	zero = (!d->zero) ? 0 : d->mw - 1;
	if (d->minus == 0 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	else if (d->zero)
		ti = write_zeros(zero, tmp, ti);
	tmp[ti++] = c;
	if (d->minus == 1 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	tmp[ti] = '\0';
	len = ft_putstrcount(tmp);
	len += (c == 0) ? write_null(d) : 0;
	ft_strdel(&tmp);
	return (len);
}

int	ft_printf_s(char *str, t_struct *d)
{
	char	*tmp;
	int		spaces;
	int		zero;
	int		len;
	int		ti;

	ti = 0;
	if (!str)
		return (write_null(d));
	len = ft_strlen(str);
	tmp = ft_strnew((d->mw > len) ? d->mw : len);
	spaces = count_spaces(d, len);
	if (!d->minus && spaces > 0 && !d->zero)
		ti = write_spaces(spaces, tmp, ti);
	else if ((zero = d->mw - len) > 0 && d->zero && !d->minus)
		ti = write_zeros(zero, tmp, ti);
	if (d->p)
		while (((!d->minus) ? ti - spaces : ti) < d->p && *str != '\0')
			tmp[ti++] = *str++;
	else
		while (*str)
			tmp[ti++] = *str++;
	if (d->minus && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	return (ft_putstrdel(&tmp, ti));
}
