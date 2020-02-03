/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:02:17 by dkathlee          #+#    #+#             */
/*   Updated: 2019/11/12 12:18:40 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	unsigned long long	i;
	char				zn;

	if (n < 0)
	{
		i = (unsigned long long)(-n);
		zn = '-';
	}
	else
	{
		i = (unsigned long long)(n);
		zn = '+';
	}
	return (ft_itoa_ull(i, zn));
}
