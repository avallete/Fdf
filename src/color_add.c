/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:54:54 by avallete          #+#    #+#             */
/*   Updated: 2015/01/07 12:23:59 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

int		ft_distance(t_coord start, t_coord end)
{
	if (abs((end.x) - (start.x)) > abs((end.y) - (start.y)))
		return (abs((end.x) - (start.x)));
	if (abs((end.x) - (start.x)) < abs((end.y) - (start.y)))
		return (abs((end.y) - (start.y)));
	return (0);
}

void	rgb_out(t_coord coor, int *rgb)
{
	if (coor.value <= 0 && coor.value > -3)
		RGB_ASSIGN(135, 206, 250);
	if (coor.value > 0 && coor.value < 2)
		RGB_ASSIGN(144, 238, 250);
	if (coor.value >= 2 && coor.value < 5)
		RGB_ASSIGN(107, 142, 35);
	if (coor.value >= 5 && coor.value < 15)
		RGB_ASSIGN(0, 128, 0);
	if (coor.value >= 15 && coor.value < 70)
		RGB_ASSIGN(128, 128, 0);
	if (coor.value >= 70)
		RGB_ASSIGN(255, 255, 255);
	if (coor.value < 0 && coor.value > -10)
		RGB_ASSIGN(153, 204, 253);
	if (coor.value <= -10 && coor.value > -40)
		RGB_ASSIGN(65, 105, 225);
	if (coor.value <= -40)
		RGB_ASSIGN(25, 25, 112);
}

t_donn	rgb_to_drgb(t_donn donn)
{
	donn.drgb[0] = \
	(donn.rgbe[0] - donn.rgbs[0]) / (float)ft_distance(donn.start, donn.end);
	donn.drgb[1] = \
	(donn.rgbe[1] - donn.rgbs[1]) / (float)ft_distance(donn.start, donn.end);
	donn.drgb[2] = \
	(donn.rgbe[2] - donn.rgbs[2]) / (float)ft_distance(donn.start, donn.end);
	return (donn);
}

t_donn	degrad(t_donn donn)
{
	donn.rgbs[0] += (int)donn.drgb[0];
	donn.rgbs[1] += (int)donn.drgb[1];
	donn.rgbs[2] += (int)donn.drgb[2];
	return (donn);
}
