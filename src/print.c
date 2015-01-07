/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:44:52 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 17:13:48 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	follow_list(t_mle *env, t_listc *beginnext, t_listc *begin)
{
	if (beginnext && beginnext->coord.err == 0)
	{
		while (beginnext)
		{
			if (beginnext && beginnext->next && beginnext->next->coord.err == 0)
				connect_pts(env, beginnext->coord, \
						beginnext->next->coord);
			if (beginnext && begin && begin->coord.err == 0)
				connect_pts(env, beginnext->coord, \
						begin->coord);
			if (begin)
				begin = begin->next;
			beginnext = beginnext->next;
		}
	}
	if (beginnext)
		trace_vertical_iso(env, beginnext);
}

void	follow_list_carth(t_mle *env, t_listc *beginnext, t_listc *begin)
{
	if (beginnext && beginnext->coord.err == 0)
	{
		while (beginnext)
		{
			if (beginnext && beginnext->next && beginnext->next->coord.err == 0)
				connect_pts(env, beginnext->coordcarth, \
						beginnext->next->coordcarth);
			if (beginnext && begin && begin->coord.err == 0)
				connect_pts(env, beginnext->coordcarth, \
						begin->coordcarth);
			if (begin)
				begin = begin->next;
			beginnext = beginnext->next;
		}
	}
	if (beginnext)
		trace_vertical_carth(env, beginnext);
}

void	init_imgdonn(int *px, int *line, int *c, t_mle *env)
{
	*px = (4 * sizeof(char));
	*line = WINDOW_W;
	*c = 1;
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
}

void	print_map(t_mle *env, t_listc *map)
{
	t_listc *begindown;
	t_listc *beginnext;
	t_listc *begin;
	t_imgdt img;

	begin = map;
	beginnext = map;
	begindown = map;
	init_imgdonn(&img.px, &img.line, &img.c, env);
	env->img = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H);
	if (env->img)
		env->imgdata = mlx_get_data_addr(env->img, &img.px, &img.line, &img.c);
	while (begindown)
	{
		beginnext = begindown;
		begindown = begindown->down;
		begin = begindown;
		if (env->basis->iso)
			follow_list(env, beginnext, begin);
		else if (env->basis->iso == 0)
			follow_list_carth(env, beginnext, begin);
	}
	if (env->img)
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
