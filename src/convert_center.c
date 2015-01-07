/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 10:35:26 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 21:47:22 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	center(t_listc *map, int iso)
{
	int		e;
	int		diff[2];
	int		pos[2];
	t_coord coord;
	t_listc *begin;

	INIT_VAR_CENTER;
	begin = map;
	pos_center(map, pos);
	while (e++ != pos[1] && begin->down)
		begin = begin->down;
	e = 0;
	while (e++ != pos[0] && begin->next)
		begin = begin->next;
	while (begin->coordcarth.err != 1 && begin->down)
		begin = begin->down;
	iso ? (coord = begin->coord) :\
	(coord = begin->coordcarth);
	diff[0] = CENTERX - coord.x;
	diff[1] = CENTERY - coord.y;
	convert_center(map, diff[0], diff[1], iso);
}

void	convert_center(t_listc *beginlist, int xcenter, int ycenter, int iso)
{
	t_listc	*begin;
	t_listc	*beginnext;
	int		i;
	int		e;

	i = 0;
	e = 0;
	begin = beginlist;
	beginnext = beginlist;
	while (begin)
	{
		beginnext = begin;
		while (beginnext)
		{
			converter_center(beginnext, xcenter, ycenter, iso);
			beginnext = beginnext->next;
			e++;
		}
		begin = begin->down;
		i++;
	}
}

void	converter_center(t_listc *beginnext, int xcenter, int ycenter, int iso)
{
	iso ? \
		(beginnext->coord.x += xcenter) : (beginnext->coordcarth.x += xcenter);
	iso ? \
		(beginnext->coord.y += ycenter) : (beginnext->coordcarth.y += ycenter);
}

void	pos_center(t_listc *map, int *pos)
{
	t_listc	*begin;
	int		x;
	int		y;

	x = 0;
	y = 1;
	begin = map;
	while (begin)
	{
		x = 0;
		map = begin;
		if (map && map->next)
		{
			while (map->next)
			{
				x++;
				map = map->next;
			}
		}
		pos[0] < x ? (pos[0] = x) : (pos[0] += 0);
		y++;
		begin = begin->down;
	}
	pos[0] = x / 2;
	pos[1] = y / 2;
}
