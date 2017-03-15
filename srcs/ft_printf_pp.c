/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:56:56 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:43:32 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_pcnt(t_struct *d)
{
	char	*tmp;
	int		spaces;
	int		zero;
	int		len;
	int		ti;

	ti = 0;
	len = (d->mw > 0) ? d->mw : 1;
	tmp = ft_strnew(len);
	spaces = (!d->zero) ? d->mw - 1 : 0;
	zero = (!d->zero) ? 0 : d->mw - 1;
	if (d->minus == 0 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	else if (d->zero)
		ti = write_zeros(zero, tmp, ti);
	tmp[ti++] = '%';
	if (d->minus == 1 && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	return (ft_putstrdel(&tmp, ti));
}

static int	ft_printf_nullptr2(t_struct *d, int ti)
{
	char	*tmp;
	int		zero;
	int		space;

	tmp = ft_strnew((d->mw + 2 > d->p) ? d->mw : d->p + 2);
	space = (d->mw && !d->p) ? count_sp_int(d, 2, 0) - 1 :
		count_sp_int(d, 2, 0) - 2;
	zero = (d->zero && d->p > 2) ? count_zeros(d, 2, 0) : space;
	if (space && d->mw >= d->p && !d->zero && !d->minus)
		ti = write_spaces(space, tmp, 0);
	tmp[ti++] = '0';
	tmp[ti++] = 'x';
	if (d->mw && !d->p && (!d->zero || (d->zero && d->minus)))
		tmp[ti++] = '0';
	if ((zero && d->p > 2) || (d->zero && !d->minus))
		ti = write_zeros((d->p) ? d->p : d->mw - 2, tmp, ti);
	ti = (space && d->minus) ? write_spaces(space, tmp, ti) : ti;
	return (ft_putstrdel(&tmp, ti));
}

static int	ft_printf_nullptr(t_struct *d)
{
	char	*tmp;

	if (d->p == -1)
	{
		tmp = ft_strjoin("0x", "");
		return (ft_putstrdel(&tmp, 2));
	}
	else if (d->p || d->mw)
		return (ft_printf_nullptr2(d, 0));
	tmp = ft_strjoin("0x0", "");
	return (ft_putstrdel(&tmp, 3));
}

static int	ft_printf_ptr(t_struct *d, char *str, intmax_t n)
{
	char	*tmp;
	int		len;
	int		space;
	int		zero;
	int		ti;

	ti = 0;
	len = ft_strlen(str);
	tmp = ft_strnew((len + d->mw > d->p) ? len + d->mw : d->p + 2);
	space = count_sp_int(d, len, n) - 2;
	zero = (d->p > len) ? count_zeros(d, len, n) : space;
	if (space && d->mw >= d->p)
		ti = write_spaces(space, tmp, 0);
	tmp[ti++] = '0';
	tmp[ti++] = 'x';
	ti = ((zero && len < d->p) || d->zero) ? write_zeros(zero, tmp, ti) : ti;
	while (*str != '\0')
		tmp[ti++] = *str++;
	return (ft_putstrdel(&tmp, ti));
}

int			ft_printf_p(void *ptr, t_struct *d)
{
	char		*str;
	char		*tmp;
	intmax_t	n;
	int			ti;

	ti = -1;
	n = (intmax_t)ptr;
	if (n == 0)
		return (ft_printf_nullptr(d));
	tmp = ft_itoa_base(n, 16);
	while (tmp[++ti] != '\0')
	{
		if (tmp[ti] >= 'A' && tmp[ti] <= 'Z')
			tmp[ti] += 32;
	}
	if (d->p)
		return (ft_printf_ptr(d, tmp, n));
	str = ft_strjoin("0x", tmp);
	ti = ft_printf_s(str, d);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (ti);
}
