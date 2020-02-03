/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:27:58 by celva             #+#    #+#             */
/*   Updated: 2020/01/13 14:04:14 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mouse_press(int kc, int x, int y, t_all *m)
{
	if (kc == BTN_WHEEL_UP || kc == BTN_WHEEL_DOWN)
	{
		translation(m, kc);
		drawing_gpu(m);
	}
	mlx_put_image_to_window(m->ptr_init, m->ptr_win, m->ptr_img, 0, 0);
	insert_text(m);
	return (0);
}

static int	btn_letter(t_all *m, int kc)
{
	if (kc == BTN_R)
		m->t = (t_transform){(t_v3){0, 0, 0}, (t_v3){m->elem_scale,
						m->elem_scale, m->elem_scale}, (t_v3){0, 0, 0}};
	if (kc == BTN_ESC)
	{
		exit(0);
		return (0);
	}
	if (kc == BTN_X || kc == BTN_Y || kc == BTN_Z)
	{
		m->key_c = kc;
		return (0);
	}
	if (kc == BTN_P || kc == BTN_I)
		m->pr = ((kc == BTN_P) ? p_paral : p_iso);
	return (0);
}

void		rand_color(t_color *res)
{
	res->r = rand() % 255;
	res->g = rand() % 255;
	res->b = rand() % 255;
}

int			key_press(int kc, t_all *m)
{
	cl_int	err;

	if (kc == BTN_C)
	{
		rand_color(&(m->map.z_max.color));
		rand_color(&(m->map.z_min.color));
		all_pts_color(m);
		err = clEnqueueWriteBuffer(m->opencl.command, m->opencl.p_mem, CL_TRUE,
		0, sizeof(t_point_3d) * m->map.x * m->map.y, m->map.pts, 0, NULL, NULL);
		if (err != CL_SUCCESS)
			error(err, "Write buffer");
	}
	btn_letter(m, kc);
	translation(m, kc);
	if (kc == BTN_C || kc == BTN_DOWN || kc == BTN_ESC || kc == BTN_I ||
		kc == BTN_LEFT || kc == BTN_NUM_2 || kc == BTN_NUM_4 || kc == BTN_NUM_6
		|| kc == BTN_NUM_8 || kc == BTN_P || kc == BTN_R || kc == BTN_RIGHT ||
		kc == BTN_UP || kc == BTN_PLUS || kc == BTN_MIN)
		drawing_gpu(m);
	mlx_put_image_to_window(m->ptr_init, m->ptr_win, m->ptr_img, 0, 0);
	insert_text(m);
	return (0);
}
