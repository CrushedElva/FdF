/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:42:33 by celva             #+#    #+#             */
/*   Updated: 2019/11/12 17:51:35 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_ull(unsigned long long n, char zn)
{
	char		buf[23];
	char		*res;
	int			i;
	int			j;

	ft_bzero((void*)buf, 23);
	i = 1;
	if (n == 0)
		buf[i++] = '0';
	while (n != 0)
	{
		buf[i++] = n % 10 + '0';
		n /= 10;
	}
	if (zn == '-')
		buf[i++] = '-';
	if ((res = ft_strnew(i)) == NULL)
		return (NULL);
	j = 0;
	while (--i >= 0)
		res[j++] = buf[i];
	return (res);
}
