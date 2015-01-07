/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 14:02:46 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 10:43:58 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	ft_putsterr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(2, &str[i++], 1);
}

void	infos_keys(void)
{
	ft_putendl("/ ********************************** \\");
	ft_putendl(" List of key :");
	ft_putendl(" I : convert and unconvert isometric");
	ft_putendl(" P : convert and unconvert cava persp");
	ft_putendl(" U : D : change colors");
	ft_putendl(" + : - : zoom/unzoom");
	ft_putendl(" arrows : move map in any directions");
	ft_putendl(" C : center map in window");
	ft_putendl(" Echap : Quit the programme");
	ft_putendl("\\ ********************************** /");
}

void	ft_fdf(t_mle *env, t_coord startpos, char **argv)
{
	int fd;

	if ((fd = open(argv[1], O_RDWR)) != -1)
	{
		env->fd = fd;
		env->basis = init_basis(SIZE, startpos, YXI, YRI);
		env->beginlist = grep_arg(env->fd, env->basis);
		if (env->beginlist != NULL)
		{
			infos_keys();
			env->first = 1;
			center(env->beginlist, env->basis->iso);
		}
		if (env->beginlist != NULL)
			mlx_expose_hook(env->win, expose_hook, env);
		env->first = 0;
		mlx_key_hook(env->win, key_hook, env);
		mlx_loop(env->mlx);
	}
	else
		perror(argv[1]);
}

void	print_usage(char *nameprog)
{
	ft_putsterr("usage : ");
	ft_putsterr(nameprog);
	ft_putsterr(" file1\n");
}

int		main(int argc, char **argv)
{
	t_mle	env;
	t_coord startpos;

	startpos.x = POSX;
	startpos.y = POSY;
	env.beginlist = NULL;
	env.img = NULL;
	env.imgdata = NULL;
	if (argc > 1)
	{
		if ((env.mlx = mlx_init()))
		{
			if ((env.win =\
						mlx_new_window(env.mlx, WINDOW_W, WINDOW_H, "ft_fdf")))
				ft_fdf(&env, startpos, argv);
		}
	}
	else
		print_usage(argv[0]);
	return (0);
}
