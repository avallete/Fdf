/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:03:50 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 22:00:52 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	free_split_line(char **split, char **line)
{
	int i;

	i = 0;
	if (split && split[0])
	{
		while (split[i])
			i++;
		while (split[i])
		{
			free(split[i]);
			split[i] = NULL;
			i--;
		}
	}
	if (split)
	{
		free(split);
		split = NULL;
	}
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
}

void	make_good_map(char *line)
{
	int i;

	i = 0;
	if (line)
	{
		while (line[i] != '\0')
		{
			if (line[i] != ' ' && line[i] != '\0' && line[i] != '-')
			{
				if ((line[i] < '0' || line[i] > '9'))
					line[i] = ' ';
			}
			i++;
		}
	}
}

t_basis	*init_basis(int size, t_coord pos, float yxi, float yri)
{
	t_basis *base;

	base = (t_basis*)malloc(sizeof(t_basis));
	base->size = size;
	base->pos.x = pos.x;
	base->pos.y = pos.y;
	base->pos.value = 0;
	base->yxi = yxi;
	base->yri = yri;
	base->iso = 0;
	base->persp = PERSP;
	return (base);
}

void	free_list(t_listc *beginlist)
{
	t_listc	*temp;
	t_listc	*tempnext;
	t_listc	*begindown;

	begindown = beginlist;
	while (begindown->down)
	{
		tempnext = begindown;
		begindown = tempnext->down;
		while (tempnext->next)
		{
			temp = tempnext;
			if (temp)
			{
				free(temp);
				temp = NULL;
			}
			tempnext = tempnext->next;
		}
	}
}

void	kill_them_all(t_mle *env)
{
	if (env->beginlist)
		free_list(env->beginlist);
	if (env->basis)
		free(env->basis);
}
