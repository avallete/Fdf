/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_arg2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 22:22:23 by avallete          #+#    #+#             */
/*   Updated: 2015/01/03 11:49:16 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	new_line(char *split, int posline, t_listc *begin, t_basis *base)
{
	t_listc *new;

	new = create_elem(split, base->pos.x, base->pos.y + (base->size * posline)\
			, base->size);
	new->coord.err = 0;
	list_pushdown(&begin, new);
	new = NULL;
}

t_listc *first_node(char *split, t_basis *base)
{
	t_listc *begin;
	t_listc *new;

	begin = (t_listc*)malloc(sizeof(t_list));
	new = create_elem(split, base->pos.x,\
			base->pos.y + (base->size * 1), base->size);
	new->coord.err = 0;
	begin = new;
	new = NULL;
	return (begin);
}

void	split_to_list(char **split, int posline, t_listc *begin, t_basis *base)
{
	t_listc		*new;
	int			i;

	i = 1;
	while (split[i] != NULL)
	{
		new = create_elem(split[i], base->pos.x + (base->size * i),\
				base->pos.y + (base->size * posline), base->size);
		new->coord.err = 0;
		list_pushback(&begin, new);
		new = NULL;
		i++;
	}
}

void	empty_line(t_listc *begin)
{
	t_listc *new;

	if (begin)
	{
		new = create_elem("0", 0, 0, 1);
		new->coord.err = 1;
		list_pushdown(&begin, new);
		new = NULL;
	}
}
