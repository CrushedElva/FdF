#include "includes/struct.h"

static double		percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

static int			get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

static t_color get_color_line(t_point_2d current, t_point_2d start, t_point_2d end)
{
    double  percentage;

    if ((abs(end.x - start.x)) > (abs(end.y - start.y)))
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    current.color.r = get_light(start.color.r, end.color.r, percentage);
    current.color.g = get_light(start.color.g, end.color.g, percentage);
    current.color.b = get_light(start.color.b, end.color.b, percentage);
    return (current.color);
}

static void	put_pixel_to_img(	int					size_l,
								__global t_color	*str_pxs,
								t_point_2d			current,
								t_point_2d			start,
								t_point_2d			end)
{
	t_color	color;
	int		i;

	color = get_color_line(current, start, end);
	if (current.x < (X_WIN - X_TXT) && current.y < Y_WIN && current.x >= 0 && current.y >= 0)
	{
		i = size_l / 4 * current.y + current.x;
		str_pxs[i].a = color.a;
		str_pxs[i].b = color.b;
		str_pxs[i].g = color.g;
		str_pxs[i].r = color.r;
	}
}

static void	draw_line(	t_point_2d			start,
						t_point_2d			end,
						int					size_l,
						__global t_color	*str_pxs)
{
	int			dX;
	int			dY;
	int			sX;
	int			sY;
	int			error;
	int			error2;
	t_point_2d	current;
	
	dX = abs((end.x - start.x));
	dY = abs((end.y - start.y));
	sX = start.x < end.x ? 1 : -1;
	sY = start.y < end.y ? 1 : -1;
	error = dX - dY;
	current = end;
	put_pixel_to_img(size_l, str_pxs, current,	start, end);
	current = start;
	while (current.x != end.x || current.y != end.y)
	{
		put_pixel_to_img(size_l, str_pxs, current,	start, end);
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
}

t_point_3d	coord_transform(t_point_3d	one,
							t_transform	t)
{
	double x;
	double y;
	double z;

	one.x *= t.scale.x;
	one.y *= t.scale.y;
	one.z *= t.scale.z;
	x = one.x;
	y = one.y;
	z = one.z;
	one.y = y * (cos(t.rot.x)) - z * (sin(t.rot.x));
	one.z = y * (sin(t.rot.x)) + z * (cos(t.rot.x));
	
	y = one.y;
	z = one.z;
	one.x = x * (cos(t.rot.y)) + z * (sin(t.rot.y));
	one.z = z * (cos(t.rot.y)) - x * (sin(t.rot.y));
	
	x = one.x;
	z = one.z;
	one.x = x * (cos(t.rot.z)) - y * (sin(t.rot.z));
	one.y = x * (sin(t.rot.z)) + y * (cos(t.rot.z));
	one.x += t.tr.x;
	one.y += t.tr.y;
	one.z += t.tr.z;
	return(one);
}

static t_point_2d	iso(int			x_max, 
						int			y_max, 
						double		z_max,
						t_point_3d	one,
						t_transform	t)
{
    int			prev_x;
    int			prev_y;
	t_point_2d	res;
	
	one = coord_transform(one, t);
    prev_x = one.x;
    prev_y = one.y;
    res.x = (prev_x - prev_y) * cos(0.523599) + ((X_WIN - X_TXT) / 2);
    res.y = -(one.z) + (prev_x + prev_y) * sin(0.523599) + (Y_WIN / 2);
	res.color = one.color;
	return (res);
}

static t_point_2d	paral(	int			x_max, 
							int			y_max, 
							double		z_max,
							t_point_3d	one,
							t_transform	t)
{
	t_point_2d	res;
	
	one = coord_transform(one, t);
    res.x = one.x + ((X_WIN - X_TXT) / 2);
    res.y = one.y + (Y_WIN / 2);
	res.color = one.color;
	return (res);
}

__kernel void drawing(	int					y_max,
						int					x_max,
						double				z_max,
						__global t_point_3d	*p,
						t_transform			t,
						int					size_l,
						__global t_color	*str_pxs,
						int					pr)
{
	int			gid;
	int			i;
	int			j;
	t_point_2d	one;
	t_point_2d	two;

	gid = get_global_id(0);
	i = gid / x_max;
	j = gid % x_max;
	if (j + 1 < x_max && i < y_max)
	{
		if (pr == 1)
		{
			one = iso(x_max, y_max, z_max, p[i * x_max + j], t);
			two = iso(x_max, y_max, z_max, p[i * x_max + (j + 1)], t);
		}
		else
		{
			one = paral(x_max, y_max, z_max, p[i * x_max + j], t);
			two = paral(x_max, y_max, z_max, p[i * x_max + (j + 1)], t);
		}
		draw_line(one, two, size_l, str_pxs);
	}
	if (i + 1 < y_max && j < x_max)
	{
		if (pr == 1)
		{
			one = iso(x_max, y_max, z_max, p[i * x_max + j], t);
			two = iso(x_max, y_max, z_max, p[(i + 1) * x_max + j], t);
		}
		else
		{
			one = paral(x_max, y_max, z_max, p[i * x_max + j], t);
			two = paral(x_max, y_max, z_max, p[(i + 1) * x_max + j], t);
		}
		draw_line(one, two, size_l, str_pxs);
	}
}
