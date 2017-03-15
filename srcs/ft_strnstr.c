/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:43:08 by sleung            #+#    #+#             */
/*   Updated: 2016/12/05 12:53:54 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	sub;
	int		i;
	int		j;
	int		k;

	i = -1;
	if (!ft_strlen(little))
		return ((char *)big);
	while (big[++i] != '\0' && len > 0)
	{
		if ((j = 0) || big[i] == little[0])
		{
			k = i;
			sub = len + 1;
			while ((big[k++] == little[j++]) && --sub > 0)
			{
				if (little[j] == '\0')
					return ((char *)big + (k - j));
				if (big[k] != little[j])
					j = 0;
			}
		}
		len--;
	}
	return (NULL);
}
