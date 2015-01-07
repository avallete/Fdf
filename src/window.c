/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:19:28 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 16:03:11 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	key_hookbis(int keycode, t_mle *env)
{
	if (keycode == 65363)
		key_move(env, 5, 0);
	if (keycode == 65362)
		key_move(env, 0, -5);
	if (keycode == 65364)
		key_move(env, 0, 5);
	if (keycode == 99)
		key_center(env);
	if (keycode == 117)
		key_persp(env, PERSP);
	if (keycode == 100)
		key_persp(env, -PERSP);
	if (keycode == 112)
		key_cava(env);
}

int		key_hook(int keycode, t_mle *env)
{
	if (keycode == 65307)
		key_echap(env);
	if (keycode == 65451)
		key_zoom(3, env);
	if (keycode == 65453)
		key_zoom(-3, env);
	if (keycode == 105)
		key_iso(env);
	if (keycode == 65361)
		key_move(env, -5, 0);
	key_hookbis(keycode, env);
	return (0);
}

int		expose_hook(t_mle *env)
{
	t_listc *list;

	list = env->beginlist;
	print_map(env, list);
	return (0);
}
