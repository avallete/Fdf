/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:31:31 by avallete          #+#    #+#             */
/*   Updated: 2015/01/04 12:10:46 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libft.h>
# define BUF_SIZE 10000

typedef struct		s_getnext
{
	int				fd;
	char			*buf;
}					t_getnext;

int					get_next_line(int const fd, char **line);
char				*join_buf(char *buf2, char *buf);
size_t				check_line(char *buf);
#endif
