/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:59:06 by celva             #+#    #+#             */
/*   Updated: 2019/12/30 16:39:58 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

t_point_3d	get_color(t_point_3d current, t_point_3d start, t_point_3d end)
{
	double	percentage;

	percentage = percent(start.z, end.z, current.z);
	current.color.r = get_light(start.color.r, end.color.r, percentage);
	current.color.g = get_light(start.color.g, end.color.g, percentage);
	current.color.b = get_light(start.color.b, end.color.b, percentage);
	return (current);
}

void		all_pts_color(t_all *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->map.y)
	{
		j = 0;
		while (j < m->map.x)
		{
			m->map.pts[i * m->map.x + j] = get_color(m->map.pts[i * m->map.x
											+ j], m->map.z_max, m->map.z_min);
			j++;
		}
		i++;
	}
}

void		clear(t_all *m)
{
	t_color color;
	int		i;
	int		j;

	color = (t_color){0, 0, 0, 0};
	i = 0;
	while (i < Y_WIN)
	{
		j = 0;
		while (j < X_WIN - X_TXT)
		{
			m->str_pxs[i * X_WIN + j] = color;
			j++;
		}
		i++;
	}
}
