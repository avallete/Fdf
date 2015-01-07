/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 11:12:59 by avallete          #+#    #+#             */
/*   Updated: 2014/12/23 16:08:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

t_coord	*coord_new(int xpos, int ypos, int val)
{
	t_coord *coord;

	coord = (t_coord*)malloc(sizeof(t_coord));
	coord->x = xpos;
	coord->y = ypos;
	coord->value = val;
	coord->err = 0;
	return (coord);
}

t_listc	*create_elem(char *value, int x, int y, int size)
{
	t_listc *new;
	t_coord	coordo;
	t_coord	coordocarthh;

	coordo.x = x;
	coordo.y = y;
	size = size;
	coordo.value = ((ft_atoi(value)) * PERSP);
	coordocarthh.x = x;
	coordocarthh.y = y;
	coordocarthh.value = ((ft_atoi(value)) * PERSP);
	new = (t_listc*)malloc(sizeof(t_listc));
	new->coord = coordo;
	new->coordcarth = coordocarthh;
	new->next = NULL;
	new->down = NULL;
	return (new);
}

void	list_pushback(t_listc **beginlist, t_listc *new)
{
	t_listc *begin;

	begin = *beginlist;
	if (begin)
	{
		if (new)
		{
			while (begin->down != NULL)
				begin = begin->down;
			while (begin->next != NULL)
				begin = begin->next;
			begin->next = new;
			new->next = NULL;
			new->down = NULL;
		}
	}
	else
	{
		if (new)
		{
			begin = new;
			new->next = NULL;
			new->down = NULL;
		}
	}
}

void	list_pushdown(t_listc **beginlist, t_listc *new)
{
	t_listc *begin;

	begin = *beginlist;
	if (begin)
	{
		if (new)
		{
			while (begin->down != NULL)
				begin = begin->down;
			begin->down = new;
			new->next = NULL;
			new->down = NULL;
		}
	}
}

void	print_coord_list(t_listc *beginlist)
{
	t_listc *begin;
	t_listc *beginnext;
	int		i;

	begin = beginlist;
	while (begin->down != NULL)
	{
		i = 0;
		beginnext = begin;
		while (beginnext->next)
		{
			beginnext = beginnext->next;
			i++;
		}
		begin = begin->down;
	}
}
