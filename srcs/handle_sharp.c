/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:11:25 by sleung            #+#    #+#             */
/*   Updated: 2017/03/09 16:10:52 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_sharp(t_struct *d, char **tmp, int *ti, intmax_t n)
{
	char	*ctmp;
	int		j;

	if (d->sharp && n != 0)
	{
		ctmp = *tmp;
		j = *ti;
		ctmp[j++] = '0';
		if (d->conv == 'x' || d->conv == 'X')
			ctmp[j++] = d->conv;
		*ti = j;
		*tmp = ctmp;
	}
	return (*tmp);
}
