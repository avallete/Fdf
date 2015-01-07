/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_pts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 15:54:57 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 17:01:43 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	move_pts(t_listc *beginlist, int x, int y, int iso)
{
	t_listc *begin;
	t_listc *beginnext;

	begin = beginlist;
	while (begin)
	{
		beginnext = begin;
		while (beginnext)
		{
			iso ? (beginnext->coord.x += x) : (beginnext->coordcarth.x += x);
			iso ? (beginnext->coord.y += y) : (beginnext->coordcarth.y += y);
			beginnext = beginnext->next;
		}
		begin = begin->down;
	}
}

void	list_line(t_listc *beginlist, int size, int iso, int e)
{
	t_listc *beginnext;
	t_coord	coord;
	int		i;

	beginnext = beginlist;
	i = 0;
	while (beginnext)
	{
		iso ? (coord = beginnext->coord) :\
		(coord = beginnext->coordcarth);
		coord.x += size * i, coord.y += size * e;
		iso ? (beginnext->coord = coord) :\
		(beginnext->coordcarth = coord);
		beginnext = beginnext->next;
		i++;
	}
}

void	zoom(t_listc *beginlist, int size, int iso)
{
	t_listc *begin;
	int		e;

	e = 0;
	begin = beginlist;
	while (begin)
	{
		list_line(begin, size, iso, e);
		begin = begin->down;
		e++;
	}
}

void	mod_value(t_listc *beginlist, int persp, int iso)
{
	t_listc *begin;
	t_listc *beginnext;

	iso = iso;
	begin = beginlist;
	persp = persp;
	while (begin)
	{
		beginnext = begin;
		while (beginnext)
		{
			beginnext->coord.value += persp;
			beginnext->coordcarth.value += persp;
			beginnext = beginnext->next;
		}
		begin = begin->down;
	}
}
