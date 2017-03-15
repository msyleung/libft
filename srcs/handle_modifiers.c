/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:25:32 by sleung            #+#    #+#             */
/*   Updated: 2017/03/06 13:38:32 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

uintmax_t	extract_oxu(va_list ap, t_struct *d)
{
	if (d->lm == 0)
		return (va_arg(ap, unsigned int));
	else if (d->lm == 'H')
		return ((unsigned char)va_arg(ap, int));
	else if (d->lm == 'h')
		return ((unsigned short)va_arg(ap, int));
	else if (d->lm == 'l')
		return (va_arg(ap, unsigned long));
	else if (d->lm == 'L')
		return (va_arg(ap, unsigned long long));
	else if (d->lm == 'j')
		return (va_arg(ap, uintmax_t));
	else if (d->lm == 'z')
		return (va_arg(ap, size_t));
	return (0);
}

intmax_t	extract_id(va_list ap, t_struct *d)
{
	if (d->lm == 0)
		return (va_arg(ap, int));
	else if (d->lm == 'H')
		return ((signed char)va_arg(ap, int));
	else if (d->lm == 'h')
		return ((short)va_arg(ap, int));
	else if (d->lm == 'l')
		return (va_arg(ap, long));
	else if (d->lm == 'L')
		return (va_arg(ap, long long));
	else if (d->lm == 'j')
		return (va_arg(ap, intmax_t));
	else if (d->lm == 'z')
		return (va_arg(ap, size_t));
	return (0);
}
