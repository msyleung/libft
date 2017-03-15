/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:40:57 by sleung            #+#    #+#             */
/*   Updated: 2017/03/12 15:39:59 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_wildcard(t_struct *d, t_format *f, va_list ap, int prec)
{
	int store;

	store = va_arg(ap, int);
	if (store < 0 && !prec)
	{
		d->minus += 1;
		store = -store;
	}
	else if (store < 0 && prec)
		store = 0;
	f->i++;
	return (store);
}
