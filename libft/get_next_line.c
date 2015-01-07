/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:50:29 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 21:20:56 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

size_t	check_line(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			return (i + 1);
		}
		i++;
	}
	return (i);
}

char	*join_buf(char *buf2, char *buf)
{
	buf = ft_strjoin(buf, buf2);
	ft_bzero(buf2, BUF_SIZE + 1);
	return (buf);
}

int		get_next_line(int const fd, char **line)
{
	int				f;
	char			*buf2;
	static char		*buf;
	size_t			i;

	if (fd != -1)
	{
		buf2 = (char*)malloc(sizeof(char) * BUF_SIZE + 1);
		ft_bzero(buf2, BUF_SIZE + 1);
		while ((f = read(fd, buf2, BUF_SIZE) > 0))
			buf = join_buf(buf2, buf);
		if (f < 0)
			return (-1);
		if (buf && buf[0] != '\0')
		{
			i = check_line(buf);
			*line = ft_strdup(buf);
			buf = buf + i;
			return (1);
		}
		return (0);
	}
	else
		return (-1);
}
