/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 18:03:33 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 21:21:02 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_listc *grep_arg(int fd, t_basis *base)
{
	char	*l;
	int		posline;
	char	**split;
	t_listc *begin;

	posline = 1;
	begin = NULL;
	split = NULL;
	l = NULL;
	while (get_next_line(fd, &l) > 0)
	{
		if (l)
		{
			make_good_map(l);
			if (((split = ft_strsplit(l, ' '))) && split[0] && l[0] != '\0')
			{
				begin = choice_type(split, begin, posline, base);
				posline++;
			}
			else
				empty_line(begin);
		}
		free_split_line(split, &l);
	}
	return (begin);
}

t_listc	*choice_type(char **split, t_listc *begin, int posline, t_basis *base)
{
	int i;

	i = 0;
	if (posline == 1 && i == 0)
		begin = first_node(split[0], base);
	if (posline > 1 && i == 0)
		new_line(split[0], posline, begin, base);
	i++;
	if (split[i])
		split_to_list(split, posline, begin, base);
	return (begin);
}
