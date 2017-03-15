/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:42:21 by sleung            #+#    #+#             */
/*   Updated: 2017/03/08 16:36:53 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	read_data2(va_list ap, t_struct *d)
{
	int len;

	len = 0;
	if (d->conv == 'u')
		len += ft_printf_u(extract_oxu(ap, d), d);
	else if (d->conv == 'U')
		len += ft_printf_cu(va_arg(ap, unsigned long), d);
	else if (d->conv == 'X' || d->conv == 'x')
		len += ft_printf_x(extract_oxu(ap, d), d);
	else if (d->conv == 'c' && d->lm != 'l')
		len += ft_printf_c(va_arg(ap, int), d);
	else if (d->conv == 'C' || (d->conv == 'c' && d->lm == 'l'))
		len += ft_printf_wc(va_arg(ap, wint_t), d);
	else if (d->conv == '%')
		len += ft_printf_pcnt(d);
	return (len);
}

int			read_data(va_list ap, t_struct *d, t_format *f)
{
	int len;

	len = 0;
	if (d->conv == 's' && d->lm != 'l')
		len += ft_printf_s(va_arg(ap, char *), d);
	else if (d->conv == 'S' || (d->conv == 's' && d->lm == 'l'))
		len += ft_printf_ws(va_arg(ap, wchar_t *), d, 0, 0);
	else if (d->conv == 'p')
		len += ft_printf_p(va_arg(ap, void *), d);
	else if (d->conv == 'i' || d->conv == 'd')
		len += ft_printf_i(extract_id(ap, d), d);
	else if (d->conv == 'D')
		len += ft_printf_cd(va_arg(ap, long), d);
	else if (d->conv == 'o')
		len += ft_printf_o(extract_oxu(ap, d), d);
	else if (d->conv == 'O')
		len += ft_printf_co(va_arg(ap, long), d);
	else
		len += read_data2(ap, d);
	f->i++;
	return (len);
}
