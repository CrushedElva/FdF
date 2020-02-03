/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:09:54 by celva             #+#    #+#             */
/*   Updated: 2019/11/14 14:37:47 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *m1, int n1, void *m2, int n2)
{
	void	*res;

	res = ft_memalloc(n1 + n2);
	res = ft_memcpy(res, m1, n1);
	ft_memcpy(res + n1, m2, n2);
	return (res);
}
