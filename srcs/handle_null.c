/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:24:59 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:55:07 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	write_null_conv_c(t_struct *d, char c, int ti)
{
	char	*tmp;
	int		space;

	c = 0;
	if (d->mw && !d->zero)
	{
		space = d->mw - 1;
		tmp = ft_strnew(d->mw);
		ti = write_spaces(space, tmp, 0);
		tmp[ti++] = 0;
		return (ft_putstrdel(&tmp, ti));
	}
	write(1, &c, 1);
	return (1);
}

static int	write_null_pres(t_struct *d, int ti, char *tmp, char *str)
{
	int	spaces;
	int	len;

	len = 6;
	spaces = count_spaces(d, len);
	if (!d->minus && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	if (d->p)
		while (((!d->minus) ? ti - spaces : ti) < d->p && *str != '\0')
			tmp[ti++] = *str++;
	else
		while (*str)
			tmp[ti++] = *str++;
	if (d->minus && spaces > 0)
		ti = write_spaces(spaces, tmp, ti);
	return (ti);
}

int			write_null(t_struct *d)
{
	char	*str;
	char	*tmp;
	int		ti;
	char	c;

	c = 0;
	if (d->conv == 'c' || d->conv == 'C')
		return (write_null_conv_c(d, c, 0));
	str = ft_strjoin("(null)", "");
	if ((!d->zero || (d->zero && d->minus)) &&
			(d->conv == 's' || d->conv == 'S') && d->p != -1)
	{
		ti = 0;
		tmp = ft_strnew((d->mw) ? d->mw : 6);
		ti = write_null_pres(d, ti, tmp, str);
	}
	else
	{
		tmp = ft_strnew(d->mw);
		ti = (d->zero) ? write_zeros(d->mw, tmp, 0) :
			write_spaces(d->mw, tmp, 0);
	}
	ft_strdel(&str);
	return (ft_putstrdel(&tmp, ti));
}
