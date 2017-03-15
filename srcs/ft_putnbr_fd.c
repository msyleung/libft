/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:35:11 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:51:13 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;

	mod = n;
	if (n > 2147483647 || n < -2147483648)
		return ;
	if (n == -2147483648)
		mod = -2147483647;
	if (mod < 0)
	{
		write(fd, "-", 1);
		mod *= -1;
	}
	if (mod >= 10)
	{
		if ((mod / 10) >= 10)
			ft_putnbr_fd(mod / 10, fd);
		else if ((mod / 10) < 10)
			ft_putchar_fd((mod / 10) + '0', fd);
		if (n == -2147483648)
			mod = 8;
		mod = mod % 10;
		ft_putchar_fd(mod + '0', fd);
	}
	else
		ft_putchar_fd(mod + '0', fd);
}
