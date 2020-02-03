/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:26:01 by celva             #+#    #+#             */
/*   Updated: 2019/12/30 13:25:44 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>

int			word_count(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (ft_index_simb(str[i], "0123456789ABCDEFabcdef") != -1 &&
			(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

void		col_map_in_file(char **str, int x, t_all *a, t_point_3d *pts)
{
	int now;
	int i;

	i = 0;
	(*str) += 3;
	now = a->map.x;
	pts->color.r = (*((*str)++) - '0') * 16;
	pts->color.r += (*((*str)++) - '0');
	pts->color.g = (*((*str)++) - '0') * 16;
	pts->color.g += (*((*str)++) - '0');
	pts->color.b = (*((*str)++) - '0') * 16;
	pts->color.b += (*((*str)++) - '0');
	pts->color.a = 0;
	a->f_color = 1;
}

t_point_3d	*parse_string(char *str, t_point_3d *pts, t_all *a)
{
	int i;
	int x;
	int pi;

	i = 0;
	x = 0;
	while (*str != '\0')
	{
		pi = a->map.y * a->map.x + x;
		if (*str == ' ' || *str == '\t')
			str++;
		if (ft_isdigit(*str) == 1)
		{
			pts[pi].x = x;
			pts[pi].y = a->map.y;
			pts[pi].z = ft_atoi(str);
			str += ft_intlen((long long)pts[pi].z);
			a->map.z_max = a->map.z_max.z > pts[pi].z ? a->map.z_max : pts[pi];
			a->map.z_min = a->map.z_min.z < pts[pi].z ? a->map.z_min : pts[pi];
			x++;
		}
		if (*str == ',')
			col_map_in_file(&str, x, a, &(pts[pi]));
	}
	return (pts);
}

t_point_3d	*parsing_file(char *fname, t_all *a)
{
	int			fd;
	char		*str;
	t_point_3d	*pts;
	int			gnl;
	int			now;

	if ((fd = open(fname, O_RDONLY)) == -1)
		return (NULL);
	a->map.y = 0;
	pts = ft_memalloc(0);
	while ((gnl = get_next_line(fd, &str)) != 0)
	{
		if (gnl == -1)
			return (NULL);
		now = word_count(str);
		if (a->map.x > 0 && a->map.x != now)
			return (NULL);
		else
			a->map.x = now;
		pts = memory_alloc(pts, (a->map.y * now), now);
		pts = parse_string(str, pts, a);
		a->map.y++;
		ft_memdel((void**)&str);
	}
	return (pts);
}
