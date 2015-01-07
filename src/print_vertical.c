/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 21:49:44 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 17:08:53 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mymlx.h>

void	trace_vertical_iso(t_mle *env, t_listc *begin)
{
	if (begin && begin->down && begin->coord.err == 0 \
			&& begin->down->coord.err == 0)
	{
		connect_pts(env, begin->coord, \
				begin->down->coord);
	}
}

void	trace_vertical_carth(t_mle *env, t_listc *begin)
{
	if (begin && begin->down && begin->coord.err == 0 \
			&& begin->down->coord.err == 0)
	{
		connect_pts(env, begin->coordcarth, \
				begin->down->coordcarth);
	}
}
