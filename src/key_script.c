/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_script.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 17:32:54 by avallete          #+#    #+#             */
/*   Updated: 2015/01/10 19:28:13 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	key_echap(t_mle *env)
{
	if (env->beginlist)
		kill_them_all(env);
	exit(0);
}

void	key_zoom(int mode, t_mle *env)
{
	if (env->beginlist)
	{
		zoom(env->beginlist, mode, env->basis->iso);
		if (env->beginlist)
			print_map(env, env->beginlist);
	}
}

void	key_move(t_mle *env, int x, int y)
{
	if (env->beginlist)
	{
		move_pts(env->beginlist, x, y, env->basis->iso);
		if (env->beginlist)
			print_map(env, env->beginlist);
	}
}

void	key_center(t_mle *env)
{
	if (env->beginlist)
	{
		center(env->beginlist, env->basis->iso);
		if (env->beginlist)
			print_map(env, env->beginlist);
	}
}
