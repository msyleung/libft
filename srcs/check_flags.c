/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:34:07 by sleung            #+#    #+#             */
/*   Updated: 2017/03/06 17:19:06 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	get_flags(t_struct *d, t_format *f)
{
	while (f->fo[f->i] == '#' || f->fo[f->i] == '0' || f->fo[f->i] == '-'
			|| f->fo[f->i] == ' ' || f->fo[f->i] == '+')
	{
		if (f->fo[f->i] == '#')
			d->sharp += 2;
		else if (f->fo[f->i] == '0')
			d->zero += 1;
		else if (f->fo[f->i] == '-')
			d->minus += 1;
		else if (f->fo[f->i] == ' ')
			d->space += 1;
		else if (f->fo[f->i] == '+')
			d->plus += 1;
		f->i++;
	}
}

static void	get_precision(t_struct *d, t_format *f, va_list ap)
{
	char	*pstr;
	int		n;

	n = 0;
	f->i++;
	pstr = ft_strnew(10);
	while (f->fo[f->i] >= '0' && f->fo[f->i] <= '9')
		pstr[n++] = f->fo[f->i++];
	if (!(d->p = ft_atoi(pstr)))
		d->p = -1;
	if (f->fo[f->i] == '*')
		handle_wildcard(d, f, ap, 1);
	ft_strdel(&pstr);
}

static void	get_minwidth(t_struct *d, t_format *f, va_list ap)
{
	char	*mwstr;
	int		n;

	n = 0;
	if (f->fo[f->i] != '*')
	{
		mwstr = ft_strnew(10);
		while (f->fo[f->i] >= '0' && f->fo[f->i] <= '9')
			mwstr[n++] = f->fo[f->i++];
		d->mw = ft_atoi(mwstr);
		ft_strdel(&mwstr);
	}
	else if (f->fo[f->i] == '*')
		d->mw = handle_wildcard(d, f, ap, 0);
}

static void	get_length_modifier(t_struct *d, t_format *f)
{
	d->lm = f->fo[f->i++];
	if (d->lm == 'h' && f->fo[f->i] == 'h')
	{
		d->lm = 'H';
		f->i++;
	}
	else if (d->lm == 'l' && f->fo[f->i] == 'l')
	{
		d->lm = 'L';
		f->i++;
	}
}

void		check_flags(t_struct *d, t_format *f, va_list ap)
{
	d->flag = (f->fo[f->i] == '#' || f->fo[f->i] == '0' || f->fo[f->i] == '-'
			|| f->fo[f->i] == '+' || f->fo[f->i] == ' ') ? 1 : 0;
	if (d->flag)
		get_flags(d, f);
	d->mw = ((f->fo[f->i] >= '0' && f->fo[f->i] <= '9') ||
			f->fo[f->i] == '*') ? 1 : 0;
	if (d->mw)
		get_minwidth(d, f, ap);
	d->p = (f->fo[f->i] == '.') ? 1 : 0;
	if (d->p)
		get_precision(d, f, ap);
	if (f->fo[f->i] == 'h' || f->fo[f->i] == 'l' || f->fo[f->i] == 'j'
			|| f->fo[f->i] == 'z')
		get_length_modifier(d, f);
}
