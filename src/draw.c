/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 11:33:11 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 22:12:02 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	connect_pts(t_mle *env, t_coord start, t_coord end)
{
	t_donn donn;

	donn.start = start;
	donn.end = end;
	donn.dir[0] = donn.end.x - donn.start.x;
	donn.dir[1] = donn.end.y - donn.start.y;
	donn.inc[0] = (donn.dir[0] > 0) ? 1 : -1;
	donn.inc[1] = (donn.dir[1] > 0) ? 1 : -1;
	donn.dir[0] = (donn.dir[0] > 0) ? donn.dir[0] : -donn.dir[0];
	donn.dir[1] = (donn.dir[1] > 0) ? donn.dir[1] : -donn.dir[1];
	rgb_out(start, donn.rgbs);
	rgb_out(end, donn.rgbe);
	donn = rgb_to_drgb(donn);
	draw_ptx(env, donn.start.x, donn.start.y, donn.rgbs);
	if (donn.dir[0] > donn.dir[1])
		draw_dx(donn, env);
	else
		draw_dy(donn, env);
}

void	draw_dy(t_donn donn, t_mle *env)
{
	int err;
	int i;

	i = 1;
	err = donn.dir[1] / 2;
	while (i <= donn.dir[1])
	{
		donn.start.y += donn.inc[1];
		err += donn.dir[0];
		if (err >= donn.dir[1])
		{
			err -= donn.dir[1];
			donn.start.x += donn.inc[0];
		}
		i++;
		draw_ptx(env, donn.start.x, donn.start.y, donn.rgbs);
		donn = degrad(donn);
	}
}

void	draw_dx(t_donn donn, t_mle *env)
{
	int err;
	int i;

	i = 1;
	err = donn.dir[0] / 2;
	while (i <= donn.dir[0])
	{
		donn.start.x += donn.inc[0];
		err += donn.dir[1];
		if (err >= donn.dir[0])
		{
			err -= donn.dir[0];
			donn.start.y += donn.inc[1];
		}
		i++;
		draw_ptx(env, donn.start.x, donn.start.y, donn.rgbs);
		donn = degrad(donn);
	}
}

void	draw_to_img(t_mle *env, int x, int y, int *rgb)
{
	size_t place;

	if (x > 0 && x < WINDOW_W)
	{
		place = y * (WINDOW_W * 4);
		place += x * 4;
		if (place < ((WINDOW_W * WINDOW_H) * (sizeof(char) * 4)))
		{
			env->imgdata[place] = rgb[2];
			env->imgdata[place + 1] = rgb[1];
			env->imgdata[place + 2] = rgb[0];
			env->imgdata[place + 3] = 255;
		}
	}
}

void	draw_ptx(t_mle *env, int x, int y, int *rgb)
{
	draw_to_img(env, x, y, rgb);
}
