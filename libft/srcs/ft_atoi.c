/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:00:03 by dkathlee          #+#    #+#             */
/*   Updated: 2019/10/31 16:10:32 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int			counter;
	long long	res;
	long long	buf;
	int			zn;

	res = 0;
	counter = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
										|| *str == '\r' || *str == '\f')
		str++;
	zn = *str == '-' ? -1 : 1;
	if ((*str == '-' || *str == '+') && *(str + 1) >= '0' && *(str + 1) <= '9')
		str++;
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		buf = res;
		res = res * 10 + (str[counter] - '0') * zn;
		if (zn == -1 && buf < res)
			return (0);
		if (zn == 1 && buf > res)
			return (-1);
		counter++;
	}
	return ((int)res);
}
