/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:01:14 by avallete          #+#    #+#             */
/*   Updated: 2015/01/10 19:28:44 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	key_persp(t_mle *env, int persp)
{
	if (env->beginlist)
		mod_value(env->beginlist, persp, env->basis->iso);
	if (env->beginlist)
		print_map(env, env->beginlist);
}

void	key_iso(t_mle *env)
{
	if (env->beginlist && env->basis->iso == 0)
	{
		convert_iso(env->beginlist, env->basis->size);
		env->basis->iso = 1;
		center(env->beginlist, env->basis->iso);
	}
	else
		env->basis->iso = 0;
	if (env->beginlist)
		print_map(env, env->beginlist);
}

void	key_cava(t_mle *env)
{
	if (env->beginlist && env->basis->iso == 0)
	{
		convert_cava(env->beginlist, env->basis->size);
		env->basis->iso = 1;
		center(env->beginlist, env->basis->iso);
	}
	else
		env->basis->iso = 0;
	if (env->beginlist)
		print_map(env, env->beginlist);
}
