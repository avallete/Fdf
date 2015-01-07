/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:35:06 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 22:04:39 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	convert_iso(t_listc *beginlist, int size)
{
	t_listc *begin;
	t_listc *beginnext;

	begin = beginlist;
	while (begin)
	{
		beginnext = begin;
		while (beginnext)
		{
			converter_iso(beginnext, size);
			beginnext = beginnext->next;
		}
		begin = begin->down;
	}
}

void	convert_cava(t_listc *beginlist, int size)
{
	t_listc *begin;
	t_listc *beginnext;

	begin = beginlist;
	while (begin)
	{
		beginnext = begin;
		while (beginnext)
		{
			converter_cava(beginnext, size);
			beginnext = beginnext->next;
		}
		begin = begin->down;
	}
}
