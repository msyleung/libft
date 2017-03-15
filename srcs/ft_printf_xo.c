/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:35:12 by sleung            #+#    #+#             */
/*   Updated: 2017/03/08 16:28:50 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_xoxo(uintmax_t n, char *str, t_struct *d)
{
	char	*tmp;
	int		zero;
	int		space;
	int		ti;
	int		len;

	ti = 0;
	len = (str[0] == 0) ? 0 : ft_strlen(str);
	tmp = ft_strnew((len > d->p) ? len + d->mw + d->sharp : d->p + d->sharp);
	space = (d->plus) ? count_sp_int(d, len, n) + 1 : count_sp_int(d, len, n);
	zero = (!d->zero || (d->p > len)) ? count_zeros(d, len, n) : space;
	handle_flags(d, &space, &zero, n);
	space -= (d->space) ? 1 : 0;
	if (space && !d->minus && !d->zero && d->mw >= d->p)
		ti = write_spaces(space, tmp, 0);
	else if (space && !d->minus && d->zero && d->mw >= d->p &&
			(d->p > len || d->p == -1))
		ti = write_spaces(space, tmp, 0);
	if (d->p == -1 && n == 0 && (d->conv == 'x' || d->conv == 'X' || !d->sharp))
		return (ft_putstrdel(&tmp, ti));
	tmp = handle_sharp(d, &tmp, &ti, n);
	ti = ((zero && len < d->p) || d->zero) ? write_zeros(zero, tmp, ti) : ti;
	tmp = ft_stricpy(tmp, &ti, str);
	ti = (space && d->minus) ? write_spaces(space, tmp, ti) : ti;
	return (ft_putstrdel(&tmp, ti));
}

int			ft_printf_o(uintmax_t n, t_struct *d)
{
	char	*str;
	int		len;

	str = ft_itoa_base_uns_long(n, 8);
	len = ft_printf_xoxo(n, str, d);
	ft_strdel(&str);
	return (len);
}

int			ft_printf_co(uintmax_t n, t_struct *d)
{
	char	*str;
	int		len;

	str = ft_itoa_base_uns_long(n, 8);
	len = ft_printf_xoxo(n, str, d);
	ft_strdel(&str);
	return (len);
}

int			ft_printf_x(uintmax_t n, t_struct *d)
{
	char	*str;
	int		len;

	len = -1;
	if (n < 2147483647)
		str = ft_itoa_base(n, 16);
	else
		str = ft_itoa_base_uns_long(n, 16);
	if (d->conv == 'x')
	{
		while (str[++len] != '\0')
		{
			if (str[len] >= 'A' && str[len] <= 'Z')
				str[len] += 32;
		}
	}
	len = ft_printf_xoxo(n, str, d);
	ft_strdel(&str);
	return (len);
}
