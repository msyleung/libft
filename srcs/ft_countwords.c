/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:29:23 by sleung            #+#    #+#             */
/*   Updated: 2016/12/11 13:32:18 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(const char *s, char c)
{
	int	words;
	int	count;

	count = 0;
	words = 0;
	while (s[count] != '\0')
	{
		while (s[count] != c && s[count] != '\0')
		{
			count++;
			if (s[count] == c || s[count] == '\0')
			{
				words++;
				if (s[count] == '\0')
					return (words);
			}
		}
		count++;
	}
	return (words);
}
