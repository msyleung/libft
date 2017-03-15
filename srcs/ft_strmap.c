/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:29:31 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:52:40 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	fresh = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!fresh || !s || !str)
		return (NULL);
	while (str[i] != '\0')
	{
		fresh[i] = (*f)(str[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
