/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:45:43 by celva             #+#    #+#             */
/*   Updated: 2019/12/30 17:05:22 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "ft_printf.h"
# include "keys.h"
# include "struct.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <OpenCL/opencl.h>
# include <OpenCL/cl.h>
# include <OpenCL/cl_gl.h>
# include <OpenCL/cl_gl_ext.h>
# include <OpenCL/cl_ext.h>
# include <OpenCL/gcl.h>

typedef enum
{
	p_paral, p_iso
}	t_project;
typedef struct	s_map
{
	int			x;
	int			y;
	t_point_3d	z_max;
	t_point_3d	z_min;
	t_point_3d	*pts;
}				t_map;
typedef struct	s_opencl
{
	cl_context			context;
	cl_device_id		device;
	cl_command_queue	command;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				pxs_mem;
	cl_mem				p_mem;
}				t_opencl;
typedef struct	s_all
{
	int			bits_pp;
	double		elem_scale;
	int			endian;
	int			f_color;
	int			key_c;
	t_map		map;
	t_opencl	opencl;
	void		*ptr_win;
	void		*ptr_init;
	void		*ptr_img;
	t_project	pr;
	int			size_l;
	t_color		*str_pxs;
	t_transform	t;
}				t_all;

void			all_pts_color(t_all *m);
int				count_num(char *str);
void			clear(t_all *m);
int				convert_color(t_color color);
t_point_3d		coord_transform(t_point_3d one, t_all *a);
void			color_gui(t_all *m);
void			draw_line(t_point_2d one, t_point_2d two, t_all *p);
void			drawing(t_all *a);
void			drawing_gpu(t_all *a);
void			error(cl_int err, char *str);
t_point_3d		get_color(t_point_3d current, t_point_3d start, t_point_3d end);
int				get_light(int start, int end, double percentage);
t_point_2d		iso(t_point_3d one, t_all *a);
void			init_cl(t_all *a);
t_all			*init_fdf(char *fname);
void			insert_text(t_all *m);
int				key_press(int kc, t_all *m);
int				mouse_press(int kc, int x, int y, t_all *m);
t_point_3d		*memory_alloc(t_point_3d *m, int l, int y);
t_point_3d		*parsing_file(char *fname, t_all *a);
void			put_pixel_to_img(t_all *a, t_point_2d current,
								t_point_2d start, t_point_2d end);
double			percent(int start, int end, int current);
void			translation(t_all *m, int kc);
int				word_count(char *str);

#endif
