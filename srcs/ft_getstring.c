/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:24:56 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:39:56 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getstring(const char *s, char c, int start)
{
	int		count;
	int		end;
	int		letters;
	char	*string;

	count = 0;
	end = start;
	letters = 0;
	while (s[end] != c && s[end] != '\0')
	{
		letters++;
		end++;
	}
	string = (char *)malloc(sizeof(char) * (letters + 1));
	if (!string)
		return (NULL);
	while (end >= start)
		string[count++] = s[start++];
	string[letters] = '\0';
	return (string);
}
