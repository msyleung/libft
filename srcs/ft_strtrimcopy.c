/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimcopy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:37:34 by sleung            #+#    #+#             */
/*   Updated: 2016/12/11 14:09:33 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimcopy(int len, char const *s, char *fresh)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (len >= n)
		fresh[n++] = s[i++];
	fresh[n] = '\0';
	return (fresh);
}
