/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:32:07 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:40:19 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_isneg(int n, int len, char *fresh)
{
	int	count;
	int	mod;
	int	nb;

	count = 0;
	nb = n;
	if (n == -2147483648)
		nb = -2147483647;
	fresh[count++] = '-';
	nb *= -1;
	while (nb >= 10)
	{
		mod = nb % 10;
		if (n == -2147483648 && nb == 2147483647)
			mod = 8;
		fresh[len - count] = mod + '0';
		count++;
		nb = nb / 10;
	}
	mod = nb % 10;
	fresh[len - count] = mod + '0';
	fresh[len] = '\0';
	return (fresh);
}

static char	*ft_ispos(int n, int len, char *fresh)
{
	int	count;
	int	mod;
	int	nb;

	count = 0;
	nb = n;
	len -= 1;
	while (nb >= 10)
	{
		mod = nb % 10;
		fresh[len - count] = mod + '0';
		count++;
		nb = nb / 10;
	}
	mod = nb % 10;
	fresh[0] = mod + '0';
	fresh[len + 1] = '\0';
	return (fresh);
}

char		*ft_itoa(int n)
{
	char	*fresh;
	int		nb;
	int		len;

	nb = n;
	if (n == -2147483648)
		nb = -2147483647;
	len = ft_intlen(nb);
	fresh = (char *)malloc(sizeof(char) * (len) + 1);
	if (!fresh)
		return (NULL);
	if (nb < 0)
		fresh = ft_isneg(n, len, fresh);
	else
		fresh = ft_ispos(n, len, fresh);
	return (fresh);
}
