/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:17:43 by celva             #+#    #+#             */
/*   Updated: 2020/01/13 14:43:35 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_coord(int kc, t_all *m)
{
	if (kc == BTN_WHEEL_DOWN || kc == BTN_MIN)
	{
		m->t.scale.x /= 1.1;
		m->t.scale.y /= 1.1;
		m->t.scale.z /= 1.1;
	}
	if (m->key_c != -1)
	{
		if (kc == BTN_NUM_6 && m->key_c == BTN_X)
			m->t.rot.x += 0.1;
		if (kc == BTN_NUM_6 && m->key_c == BTN_Y)
			m->t.rot.y += 0.1;
		if (kc == BTN_NUM_6 && m->key_c == BTN_Z)
			m->t.rot.z += 0.1;
		if (kc == BTN_NUM_4 && m->key_c == BTN_X)
			m->t.rot.x -= 0.1;
		if (kc == BTN_NUM_4 && m->key_c == BTN_Y)
			m->t.rot.y -= 0.1;
		if (kc == BTN_NUM_4 && m->key_c == BTN_Z)
			m->t.rot.z -= 0.1;
	}
}

void	translation(t_all *m, int kc)
{
	if (kc == BTN_UP || kc == BTN_DOWN)
		m->t.tr.y += (kc == BTN_UP ? -10 : 10);
	if (kc == BTN_RIGHT || kc == BTN_LEFT)
		m->t.tr.x += (kc == BTN_RIGHT ? 10 : -10);
	if (kc == BTN_NUM_8 || kc == BTN_NUM_2)
		m->t.tr.z += (kc == BTN_NUM_8 ? 10 : -10);
	if (kc == BTN_WHEEL_UP || kc == BTN_PLUS)
	{
		m->t.scale.x *= 1.1;
		m->t.scale.y *= 1.1;
		m->t.scale.z *= 1.1;
	}
	if (kc == BTN_WHEEL_DOWN || kc == BTN_MIN || m->key_c != -1)
		parse_coord(kc, m);
}
