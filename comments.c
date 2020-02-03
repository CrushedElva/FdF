/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:06:01 by celva             #+#    #+#             */
/*   Updated: 2019/12/27 11:52:40 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*t_point_2d	iso(t_point_3d one, t_all *a)
{
	double k;
    int prev_x;
    int prev_y;
	t_point_2d res;
	
	k = a->x > a->y ? a->x : a->y;
	k = k > a->z_max.z ? k : a->z_max.z;
	k = (X_WIN * 0.4) / k;
	one = coord_transform(one, a);
    prev_x = k * one.x;
    prev_y = k * one.y;
	one.z *= k;
    res.x = (prev_x - prev_y) * cos(0.523599) + (X_WIN / 2);
    res.y = -(one.z) + (prev_x + prev_y) * sin(0.523599) + (Y_WIN / 2);
	res.color = one.color;
	return (res);
}*/

/* linux
	if (m->key_c != -1)
	{
		if (kc == 65432 && m->key_c == 120)
			m->t.rot.x += 0.1;
		if (kc == 65432 && m->key_c == 121)
			m->t.rot.y += 0.1;
		if (kc == 65432 && m->key_c == 122)
			m->t.rot.z += 0.1;
		if (kc == 65430 && m->key_c == 120)
			m->t.rot.x -= 0.1;
		if (kc == 65430 && m->key_c == 121)
			m->t.rot.y -= 0.1;
		if (kc == 65430 && m->key_c == 122)
			m->t.rot.z -= 0.1;
	}*/

/*if (kc >= 120 && kc <= 122)			//x, y, z key linux
	{
		m->key_c = kc;
		return (0);
	}*/

/*int			convert_color(t_color color)
{
	return (color.b | color.g << 8 | color.r << 16 | color.a << 24);
}*/

/*t_color get_color_line(t_point_2d current, t_point_2d start, t_point_2d end)
{
	int		c_c;
	int		c_e;
	int		c_s;
    double  percentage;

	c_c = convert_color(current.color);
	c_e = convert_color(end.color);
	c_s = convert_color(start.color);
    if (c_c == c_e)
        return (current.color);
    if ((ABS(end.x - start.x)) > (ABS(end.y - start.y)))
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    current.color.r = get_light((c_s >> 16) & 0xFF, (c_e >> 16) & 0xFF, percentage);
    current.color.g = get_light((c_s >> 8) & 0xFF, (c_e >> 8) & 0xFF, percentage);
    current.color.b = get_light(c_s & 0xFF, c_e & 0xFF, percentage);
    return (current.color);
}*/

/*int		word_count(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 && ft_isdigit(str[i + 1]) == 0)
			n++;
		i++;
	}
	return (n);
}

t_point_3d	**memory_alloc(t_point_3d **m, int now, int y)
{
	m = ft_realloc(m, (y * sizeof(t_point_3d*)), ((1 + y) * sizeof(t_point_3d*)));
	m[y] = ft_memalloc((sizeof(t_point_3d)) * now);
	return (m);
}

int		count_num(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 && ft_isdigit(str[i + 1]) == 0)
			n++;
		i++;
	}
	return (n);
}

t_point_3d	**parsing_file(char *fname, t_all *a)
{
	int		fd;
	char	*str;
	t_point_3d	**pts;
	int		i;
	int		x;
	int		y;
	int		gnl;
	int		now;

	if ((fd = open(fname, O_RDONLY)) == -1)
		return (NULL);
	y = 0;
	pts = ft_memalloc(0);
	while ((gnl = get_next_line(fd, &str)) != 0)
	{
		if (gnl == -1)
			return (NULL);
		now = word_count(str);
		pts = memory_alloc(pts, now, y);
		i = 0;
		x = 0;
		while (str[i] != '\0')
		{
			if (str[i] == ' ' || str[i] == '\t')
				i++;
			if (ft_isdigit(str[i]) == 1)
			{
				pts[y][x].x = x;
				pts[y][x].y = y;
				int z = ft_atoi(str + i);
				pts[y][x].z = ft_atoi(str + i);
				i += ft_intlen((long long)pts[y][x].z);
				x++;
			}
		}
		y++;
		a->y = y;
		a->x = x;
		ft_memdel((void**)&str);
	}
	return (pts);
}*/

/*void	put_pixel_to_img(t_all *a, t_point_2d current, t_point_2d start, t_point_2d end)
{
	t_color	color;
	int		i;

	color = get_color_line(current, start, end);
	if (current.x < X_WIN && current.y < Y_WIN && current.x >= 0 && current.y >= 0)
	{
		i = a->size_l / 4 * current.y + current.x;
		a->str_pxs[i].a = color.a;
		a->str_pxs[i].b = color.b;
		a->str_pxs[i].g = color.g;
		a->str_pxs[i].r = color.r;
	}
}*/

/*void	draw_line(t_point_2d start, t_point_2d end, t_all *p)
{
	int		dX;
	int		dY;
	int		sX;
	int		sY;
	int		error;
	int		error2;
	t_point_2d	current;
	
	dX = ABS((end.x - start.x));
	dY = ABS((end.y - start.y));
	sX = start.x < end.x ? 1 : -1;
	sY = start.y < end.y ? 1 : -1;
	error = dX - dY;
	current = end;
	put_pixel_to_img(p, current, start, end);
	current = start;
	while (current.x != end.x || current.y != end.y)
	{
		put_pixel_to_img(p, current, start, end);
		error2 = error * 2;
		if (error2 > -dY)
		{
			error -= dY;
			current.x += sX;
		}
		if (error2 < dX)
		{
			error += dX;
			current.y += sY;
		}
	}
}*/

/*t_point_3d	coord_transform(t_point_3d one, t_all *a)
{
	double x;
	double y;
	double z;

	one.x *= a->t.scale.x;
	one.y *= a->t.scale.y;
	one.z *= a->t.scale.z;
	x = one.x;
	y = one.y;
	z = one.z;
	one.y = y * (cos(a->t.rot.x)) - z * (sin(a->t.rot.x));
	one.z = y * (sin(a->t.rot.x)) + z * (cos(a->t.rot.x));
	
	y = one.y;
	z = one.z;
	one.x = x * (cos(a->t.rot.y)) + z * (sin(a->t.rot.y));
	one.z = z * (cos(a->t.rot.y)) - x * (sin(a->t.rot.y));
	
	x = one.x;
	z = one.z;
	one.x = x * (cos(a->t.rot.z)) - y * (sin(a->t.rot.z));
	one.y = x * (sin(a->t.rot.z)) + y * (cos(a->t.rot.z));
	one.x += a->t.tr.x;
	one.y += a->t.tr.y;
	one.z += a->t.tr.z;
	return(one);
}*/

/*void		drawing(t_all *a)
{
	t_point_3d	**p;
	int			i;
	int			j;
	t_point_2d	one;
	t_point_2d	two;
	
	i = 0;
	p = a->map.pts;
	while (i < a->y)
	{
		j = 0;
		while (j < a->x)
		{
			if (j + 1 != a->x)
			{
				one = iso(p[i][j], a);
				two = iso(p[i][j + 1], a);
				draw_line(one, two, a);
			}
			if (i + 1 != a->y)
			{
				one = iso(p[i][j], a);
				two = iso(p[i + 1][j], a);
				draw_line(one, two, a);
			}
			j++;
		}
		i++;
	}
}*/

//Вывод составляющих цвета
/*i = 0;
while (i < m->map.y)
{
	j = 0;
	while (j < m->map.x)
	{
		printf("r - %d; g - %d; b - %d\n", m->map.pts[i * m->map.x + j].color.r,
		m->map.pts[i * m->map.x + j].color.g, m->map.pts[i * m->map.x + j].color.b);
		j++;
	}
	ft_putendl("");
	i++;
}*/
