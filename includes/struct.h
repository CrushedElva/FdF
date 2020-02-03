/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:14:57 by celva             #+#    #+#             */
/*   Updated: 2019/12/30 15:18:27 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define Y_WIN 1000
# define X_WIN 1300
# define X_TXT 300
# define Y_TXT 1000

typedef struct	s_v3
{
	double x;
	double y;
	double z;
}				t_v3;
typedef struct	s_transform
{
	t_v3	rot;
	t_v3	scale;
	t_v3	tr;
}				t_transform;
typedef struct	s_color
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}				t_color;
typedef struct	s_point_2d
{
	t_color	color;
	int		x;
	int		y;
}				t_point_2d;
typedef struct	s_point_3d
{
	t_color	color;
	double	x;
	double	y;
	double	z;
}				t_point_3d;
#endif
