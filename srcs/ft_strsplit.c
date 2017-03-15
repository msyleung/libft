/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:54:27 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:53:12 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_makearray(int wc, char c, char const *s, char **fresh)
{
	int	fc;
	int	sc;

	sc = 0;
	fc = 0;
	while (wc > 0)
	{
		while (s[sc] != '\0')
		{
			if (s[sc] != c)
			{
				fresh[fc++] = ft_getstring(s, c, sc);
				wc--;
				while (s[sc] != c && s[sc] != '\0')
					sc++;
			}
			else
				sc++;
		}
		wc--;
	}
	fresh[fc] = NULL;
	return (fresh);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		fc;
	int		wc;

	fc = 0;
	if (!s)
		return (NULL);
	wc = ft_countwords(s, c);
	fresh = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!fresh)
		return (NULL);
	fresh = ft_makearray(wc, c, s, fresh);
	return (fresh);
}
