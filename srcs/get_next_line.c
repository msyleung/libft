/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:40:01 by sleung            #+#    #+#             */
/*   Updated: 2017/01/29 13:29:26 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	extract_line(t_files *data)
{
	char	*str;
	int		ln_len;
	int		n;

	ln_len = 0;
	n = -1;
	if (*(data->file) == '\0')
		return (0);
	while (data->file[ln_len] != '\n' && data->file[ln_len] != '\0')
		ln_len++;
	str = (char *)ft_memalloc(ln_len + 1);
	while ((ln_len--) >= 0)
		str[++n] = *(data->file)++;
	str[n] = '\0';
	if (!(data->fd_line = ft_strjoin("", str)))
		return (-1);
	if (str != NULL)
		ft_strdel(&str);
	data->reading = 42;
	return (1);
}

static void	data_init(t_files *data)
{
	data->s = S_ULIM;
	data->file = ft_strnew(data->s);
	data->n = 0;
	data->fd_line = NULL;
	data->reading = 0;
}

static int	read_buff(const int fd, t_files *data)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		count;

	if ((ret = read(fd, buff, 0)) != 0)
		return (0);
	data_init(data);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		count = 0;
		buff[ret] = '\0';
		while (buff[count] != '\0')
		{
			data->file[data->n++] = buff[count++];
			if (data->n == data->s)
			{
				data->s = data->n * data->n;
				data->file = ft_realloc((void *)data->file, data->n, data->s);
			}
		}
	}
	data->file[data->n] = '\0';
	return (1);
}

static void	erase_data(t_files *data)
{
	data->reading = 0;
	if (data->fd_line != NULL)
		ft_strdel(&data->fd_line);
	if (data != NULL)
	{
		data->file = NULL;
		data->n = 0;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_files	*data;
	int				result;

	if (fd < 0 || !line || BUFF_SIZE < 0 || fd > S_ULIM)
		return (-1);
	if (!data && !(data = (t_files *)malloc(sizeof(t_files))))
		return (-1);
	if (data->reading != 42 && !read_buff(fd, data))
		return (-1);
	if ((result = extract_line(data)) == 1)
	{
		if (!(*line = ft_strjoin("", data->fd_line)))
			return (-1);
		ft_strdel(&data->fd_line);
	}
	if (result == 0 || result == -1 || data->file[0] == '\0')
	{
		erase_data(data);
		if (result == 0)
			*line = NULL;
	}
	return (result);
}
