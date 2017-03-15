/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:54:34 by sleung            #+#    #+#             */
/*   Updated: 2016/12/11 11:39:54 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	count;
	int		result;

	count = 0;
	result = 1;
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while (n > count && s1[count] != '\0')
	{
		if (s1[count] != s2[count])
			result = 0;
		count++;
	}
	count = 0;
	while (n > count && s2[count] != '\0')
	{
		if (s2[count] != s1[count])
			result = 0;
		count++;
	}
	return (result);
}
