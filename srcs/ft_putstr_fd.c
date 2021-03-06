/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:30:54 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:51:38 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	n;

	n = 0;
	if (!s)
		return ;
	while (s[n])
	{
		write(fd, &s[n], 1);
		n++;
	}
}
