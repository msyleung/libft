/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:04:47 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:50:59 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	mod;

	mod = n;
	if (mod > 2147483647 || mod < -2147483648)
		return ;
	if (n == -2147483648)
		mod = -2147483647;
	if (mod < 0)
	{
		ft_putchar('-');
		mod *= -1;
	}
	if (mod >= 10)
	{
		if ((mod / 10) >= 10)
			ft_putnbr(mod / 10);
		else if ((mod / 10) < 10)
			ft_putchar((mod / 10) + '0');
		if (n == -2147483648)
			mod = 8;
		mod = mod % 10;
		ft_putchar(mod + '0');
	}
	else
		ft_putchar(mod + '0');
}
