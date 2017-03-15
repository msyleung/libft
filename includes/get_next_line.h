/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:53:20 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:38:00 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42
# define S_ULIM 4864

# include "libft.h"

typedef struct	s_files
{
	char		*file;
	char		*fd_line;
	int			reading;
	int			s;
	int			n;
}				t_files;

int				get_next_line(const int fd, char **line);

#endif
