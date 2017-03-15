/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:46:29 by sleung            #+#    #+#             */
/*   Updated: 2016/12/11 13:51:10 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strtrimlen(char const *s)
{
	int	i;
	int end;

	i = 0;
	end = ft_strlen(s) - 1;
	if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t'
			&& s[end] != ' ' && s[end] != '\n' && s[end] != '\t')
		return (end - i);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (end >= i)
		return (end - i);
	else
		return (0);
}
