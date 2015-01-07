/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 11:14:52 by avallete          #+#    #+#             */
/*   Updated: 2015/01/07 12:20:13 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H
# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define CENTERX (WINDOW_W / 2)
# define CENTERY (WINDOW_H / 2)
# define POSX 500
# define POSY 300
# define SIZE 20
# define HIGHT(x, y, z) ((z * x) / (y + 1))
# define YXI 0.58
# define YRI 3.536
# define PERSP 2
# define RED(rgb) ((rgb[0] & 0xFF) << 16)
# define GREEN(rgb) ((rgb[1] & 0xFF) << 8)
# define BLUE(rgb) ((rgb[2] & 0xFF))
# define RGB_TO_HEX(rgb) ((RED(rgb) + GREEN(rgb) + BLUE(rgb)))
# define INIT_DIFF ((diff[0] = 0), (diff[1] = 0))
# define INIT_VAR_CENTER ((e = 0), INIT_DIFF, (pos[0] = 0), (pos[1] = 0))
# define RGB_ASSIGN(r, g, b) (((rgb[0] = r), (rgb[1] = g), (rgb[2] = b)))
# define WINDOW_W 2500
# define WINDOW_H 1540

typedef	struct		s_coord
{
	int				x;
	int				y;
	int				value;
	int				err;
}					t_coord;

typedef struct		s_basis
{
	int				size;
	t_coord			pos;
	float			yxi;
	float			yri;
	int				iso;
	int				persp;
}					t_basis;

typedef struct		s_listc
{
	t_coord			coord;
	t_coord			coordcarth;
	struct s_listc	*next;
	struct s_listc	*down;
}					t_listc;

typedef struct		s_mle
{
	char			first;
	void			*img;
	char			*imgdata;
	void			*mlx;
	void			*win;
	t_listc			*beginlist;
	t_basis			*basis;
	int				*pos;
	int				fd;
}					t_mle;

typedef struct		s_donn
{
	int				dir[2];
	int				inc[2];
	int				rgbs[3];
	int				rgbe[3];
	int				drgb[3];
	t_coord			start;
	t_coord			end;
}					t_donn;

typedef struct		s_imgdonn
{
	int				px;
	int				line;
	int				c;
}					t_imgdt;

/*
** ----------
** Misc
** ----------
*/

int					ft_distance(t_coord start, t_coord end);
t_donn				degrad(t_donn donn);
t_donn				rgb_to_drgb(t_donn donn);
void				rgb_out(t_coord coor, int *rgb);
void				infos_keys(void);
void				print_usage(char *nameprog);

/*
** --------------------
** Img
** --------------------
*/

void				draw_to_img(t_mle *env, int x, int y, int *rgb);
void				connect_pts_img(t_mle *env, t_coord start, t_coord end);
void				print_map_img(t_mle *env, t_listc *map);
void				follow_list(t_mle *env, t_listc *beginnext, t_listc *begin);
void				print_last_line_img(t_mle *env, t_listc *lastline);
void				draw_dx_img(t_donn donn, t_mle *env);
void				draw_dy_img(t_donn donn, t_mle *env);
/*
** --------------------
** Struct init
** --------------------
*/
t_coord				*coord_new(int xpos, int ypos, int val);
void				modif_coord(t_coord *old, t_coord *new);
t_basis				*init_basis(int size, t_coord pos, float yxi, float yri);
void				init_imgdonn(int *px, int *line, int *c, t_mle *env);
/*
** --------------------
** Modify coords
** --------------------
*/

/*
** Convert iso
*/

void				convert_iso(t_listc *beginlist, int size);
void				converter_iso(t_listc *beginnext, int size);
void				convert_cava(t_listc *beginlist, int size);
void				converter_cava(t_listc *beginnext, int size);

/*
** Center
*/

void				pos_center(t_listc *map, int *pos);
void				center(t_listc *map, int iso);
void				convert_center(t_listc *beginlist,\
					int xcenter, int ycenter, int iso);
void				converter_center(t_listc *beginnext,\
					int xcenter, int ycenter, int iso);

/*
** --------------------
** List
** --------------------
*/

t_listc				*create_elem(char *value, int x, int y, int size);
void				list_pushback(t_listc **beginlist, t_listc *new);
void				list_pushdown(t_listc **beginlist, t_listc *new);
void				print_coord_list(t_listc *beginlist);

/*
** ---------------------
** Print map
** ---------------------
*/

void				print_map(t_mle *env, t_listc *map);
void				print_last_line(t_mle *env, t_listc *lastline);
void				trace_vertical_iso(t_mle *env, t_listc *begin);
void				trace_vertical_carth(t_mle *env, t_listc *begin);

/*
** ---------------------
** Draw something
** ---------------------
*/

void				draw_ptx(t_mle *env, int x, int y, int *rgb);
int					key_hook(int keycode, t_mle *env);

/*
** ---------------------
** Window functions
** ---------------------
*/

int					expose_hook(t_mle *env);
void				draw(t_mle *env, t_coord *start, t_coord *end);

/*
** ---------------------
** Grep args
** ---------------------
*/

t_listc				*grep_arg(int fd, t_basis *base);
void				new_line(char *split, int posline, t_listc *begin,\
					t_basis *base);
t_listc				*first_node(char *split, t_basis *base);
void				split_to_list(char **split, int posline, t_listc *begin,\
					t_basis *base);
void				empty_line(t_listc *begin);
void				make_good_map(char *line);
t_listc				*choice_type(char **split, t_listc *begin, int posline,\
					t_basis *base);

/*
** ---------------------
** Connect points
** ---------------------
*/

void				connect_pts(t_mle *env, t_coord start, t_coord end);
void				draw_dy(t_donn donn, t_mle *env);
void				draw_dx(t_donn donn, t_mle *env);

/*
** ---------------------
** Key script
** ---------------------
*/

void				move_pts(t_listc *beginlist, int x, int y, int iso);
void				zoom(t_listc *beginlist, int size, int iso);
void				list_line(t_listc *beginlist, int size, int iso, int e);
void				key_zoom(int mode, t_mle *env);
void				key_echap(t_mle *env);
void				key_center(t_mle *env);
void				key_move(t_mle *env, int x, int y);
void				key_iso(t_mle *env);
void				mod_value(t_listc *beginlist, int persp, int iso);
void				key_persp(t_mle *env, int persp);
void				key_cava(t_mle *env);

/*
** ---------------------
** Free
** ---------------------
*/

void				free_split_line(char **split, char **line);
void				kill_them_all(t_mle *env);
void				free_list(t_listc *beginlist);
#endif
