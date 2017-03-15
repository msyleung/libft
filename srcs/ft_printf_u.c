/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:56:48 by sleung            #+#    #+#             */
/*   Updated: 2017/03/08 16:27:05 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_uu(uintmax_t n, char *str, t_struct *d)
{
	char	*tmp;
	int		ti;
	int		space;
	int		zero;
	int		len;

	ti = 0;
	len = (str[0] == 0) ? 0 : ft_strlen(str);
	tmp = ft_strnew((len + d->mw > d->p) ? len + d->mw : d->p);
	space = count_sp_int(d, len, n);
	zero = (!d->zero || (d->p > len)) ? count_zeros(d, len, n) : space;
	handle_flags(d, &space, &zero, n);
	space -= (d->space) ? 1 : 0;
	if (space && !d->minus && !d->zero && d->mw >= d->p)
		ti = write_spaces(space, tmp, 0);
	else if (space && !d->minus && d->zero && d->mw >= d->p &&
			(d->p > len || d->p == -1))
		ti = write_spaces(space, tmp, 0);
	if (d->p == -1 && n == 0)
		return (ft_putstrdel(&tmp, ti));
	ti = ((zero && len < d->p) || d->zero) ? write_zeros(zero, tmp, ti) : ti;
	while (*str != '\0')
		tmp[ti++] = *str++;
	ti = (space && d->minus) ? write_spaces(space, tmp, ti) : ti;
	return (ft_putstrdel(&tmp, ti));
}

int			ft_printf_u(uintmax_t n, t_struct *d)
{
	char	*str;
	int		len;

	str = ft_itoa_base_uns_long(n, 10);
	len = ft_printf_uu(n, str, d);
	ft_strdel(&str);
	return (len);
}

int			ft_printf_cu(uintmax_t n, t_struct *d)
{
	char	*str;
	int		len;

	str = ft_itoa_base_uns_long(n, 10);
	len = ft_printf_uu(n, str, d);
	ft_strdel(&str);
	return (len);
}
