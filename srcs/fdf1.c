/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:45:39 by celva             #+#    #+#             */
/*   Updated: 2019/12/30 13:25:38 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_3d	*memory_alloc(t_point_3d *m, int l, int y)
{
	m = ft_realloc(m, (l * sizeof(t_point_3d)), ((y + l) * sizeof(t_point_3d)));
	return (m);
}

int			count_num(char *str)
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
