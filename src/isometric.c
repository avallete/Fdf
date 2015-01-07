/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:41:33 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 22:07:18 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	converter_cava(t_listc *beginnext, int size)
{
	int x;
	int y;
	int z;

	x = beginnext->coordcarth.x;
	y = beginnext->coordcarth.y;
	x = (int)((beginnext->coordcarth.x - beginnext->coordcarth.y) * 2);
	y = (int)((beginnext->coordcarth.x + beginnext->coordcarth.y) * 2);
	z = (((beginnext->coordcarth.value) * size) / 100) * PERSP;
	x += (1 * cos(2 * beginnext->coordcarth.y));
	z += ((1 * sin(2 * beginnext->coordcarth.y)));
	y -= z * 1;
	beginnext->coord.x = (int)x;
	beginnext->coord.y = (int)y;
}

void	converter_iso(t_listc *beginnext, int size)
{
	int x;
	int y;
	int z;

	x = beginnext->coordcarth.x;
	y = beginnext->coordcarth.y;
	x = (int)((beginnext->coordcarth.x - beginnext->coordcarth.y));
	y = (int)((beginnext->coordcarth.x + beginnext->coordcarth.y) / 2);
	z = (((beginnext->coordcarth.value) * size) / 100) * PERSP;
	y -= z;
	beginnext->coord.x = x;
	beginnext->coord.y = y;
}
