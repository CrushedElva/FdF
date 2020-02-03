/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:56:00 by celva             #+#    #+#             */
/*   Updated: 2019/12/30 16:37:35 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	location_img(t_all *m)
{
	double	offset_z;
	int		i;
	int		j;

	offset_z = (m->map.z_max.z - m->map.z_min.z) / 2;
	i = -1;
	while (++i < m->map.y)
	{
		j = 0;
		while (j < m->map.x)
		{
			m->map.pts[i * m->map.x + j].x -= (m->map.x / 2);
			m->map.pts[i * m->map.x + j].y -= (m->map.y / 2);
			m->map.pts[i * m->map.x + j].z -= offset_z;
			j++;
		}
	}
	m->map.z_max.z -= offset_z;
	m->map.z_min.z -= offset_z;
	if (m->f_color == 0)
	{
		m->map.z_max.color = (t_color){0, 255, 255, 0};
		m->map.z_min.color = (t_color){255, 0, 255, 0};
		all_pts_color(m);
	}
}

static void	init_ptr(t_all *m, char *fname)
{
	m->ptr_init = mlx_init();
	m->ptr_img = mlx_new_image(m->ptr_init, (X_WIN), Y_WIN);
	m->str_pxs = (t_color*)mlx_get_data_addr(m->ptr_img, &(m->bits_pp),
											&(m->size_l), &(m->endian));
	m->ptr_win = mlx_new_window(m->ptr_init, (X_WIN), Y_WIN, fname);
	init_cl(m);
}

t_all		*init_fdf(char *fname)
{
	t_all	*m;
	double	k;

	m = (t_all*)ft_memalloc(sizeof(t_all) * 1);
	m->f_color = 0;
	m->pr = p_iso;
	m->map.x = -1;
	m->map.y = -1;
	m->map.z_min = (t_point_3d){(t_color){66, 66, 66, 0}, INT32_MAX,
												INT32_MAX, INT32_MAX};
	m->map.z_max = (t_point_3d){(t_color){10, 10, 10, 0}, INT32_MIN,
												INT32_MIN, INT32_MIN};
	m->key_c = -1;
	m->map.pts = parsing_file(fname, m);
	if (m->map.pts == NULL)
		return (NULL);
	k = m->map.x > m->map.y ? m->map.x : m->map.y;
	k = (k / 2) > m->map.z_max.z ? k : m->map.z_max.z;
	k = ((X_WIN - X_TXT) * 0.4) / k;
	m->t = (t_transform){(t_v3){0, 0, 0}, (t_v3){k, k, k}, (t_v3){0, 0, 0}};
	m->elem_scale = k;
	location_img(m);
	init_ptr(m, fname);
	return (m);
}
