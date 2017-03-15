/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:30:28 by sleung            #+#    #+#             */
/*   Updated: 2017/02/01 12:40:16 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	if (!ft_strlen(little))
		return ((char *)big);
	while (big[++i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (big[k++] == little[j++])
			{
				if (little[j] == '\0')
					return ((char *)big + (k - j));
				else if (big[k] != little[j])
					j = 0;
			}
		}
	}
	return (NULL);
}
