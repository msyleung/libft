/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:55:52 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:43:13 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_id(intmax_t n, char *str, t_struct *d)
{
	char	*tmp;
	int		zero;
	int		space;
	int		ti;
	int		len;

	ti = 0;
	len = (str[0] == 0) ? 0 : ft_strlen(str);
	tmp = ft_strnew(((len + d->mw) > d->p) ? len + d->mw : d->p);
	space = count_sp_int(d, len, n);
	zero = (!d->zero || (d->p >= len)) ? count_zeros(d, len, n) : space;
	handle_flags(d, &space, &zero, n);
	if (space && !d->minus && !d->zero && len + d->mw >= d->p)
		ti = write_spaces(space, tmp, 0);
	else if (space && !d->minus && d->zero && len + d->mw >= d->p &&
			(d->p >= len || d->space || d->p == -1))
		ti = write_spaces(space, tmp, 0);
	handle_sign(d, &tmp, &str, &ti);
	if (d->p == -1 && n == 0)
		return (ft_putstrdel(&tmp, ti));
	ti = ((zero && len < d->p) || d->zero) ? write_zeros(zero, tmp, ti) : ti;
	tmp = ft_stricpy(tmp, &ti, str);
	ti = (space && d->minus) ? write_spaces(space, tmp, ti) : ti;
	return (ft_putstrdel(&tmp, ti));
}

int			ft_printf_i(intmax_t n, t_struct *d)
{
	char	*str;
	int		len;

	if (n >= -9223372036854775807)
		str = ft_itoa_base(n, 10);
	else
		str = ft_strjoin("-9223372036854775808", "");
	len = ft_printf_id(n, str, d);
	ft_strdel(&str);
	return (len);
}

int			ft_printf_cd(intmax_t n, t_struct *d)
{
	char	*str;
	int		len;

	if (n >= -9223372036854775807)
		str = ft_itoa_base(n, 10);
	else
		str = ft_strjoin("-9223372036854775808", "");
	len = ft_printf_id(n, str, d);
	ft_strdel(&str);
	return (len);
}
