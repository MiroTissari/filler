/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:22:43 by mtissari          #+#    #+#             */
/*   Updated: 2022/02/08 15:16:09 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	last_line(char **line)
{
	*line = NULL;
	return (0);
}

static int	save_line(char **str, char **line)
{
	char	*save;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_strsub (*str, 0, i);
		save = ft_strdup (&(*str)[i + 1]);
		free (*str);
		*str = save;
		if ((*str)[0] == '\0')
			ft_strdel (str);
	}
	else
	{
		*line = ft_strdup (*str);
		ft_strdel (str);
	}
	return (1);
}

static int	read_line(char **str, char **line, char *buf, int fd)
{
	char	*temp;
	int		rtn;

	rtn = read(fd, buf, BUFF_SIZE);
	while (rtn != 0)
	{
		if (rtn < 0)
			return (-1);
		buf[rtn] = '\0';
		if (str[fd])
		{
			temp = ft_strjoin (str[fd], buf);
			free (str[fd]);
			str[fd] = temp;
		}
		else
			str[fd] = ft_strdup (buf);
		if (ft_strchr(str[fd], '\n'))
			return (save_line(&str[fd], line));
		rtn = read (fd, buf, BUFF_SIZE);
	}
	if (str[fd] == NULL && rtn == 0)
		return (last_line(line));
	return (save_line(&str[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || fd > MAX_FD || !line || BUFF_SIZE < 1)
		return (-1);
	return (read_line(str, line, buf, fd));
}
