/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:28:16 by celva             #+#    #+#             */
/*   Updated: 2019/11/14 14:30:15 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin_del(void *m1, int n1, void *m2, int n2)
{
	void *res;

	res = ft_memjoin(m1, n1, m2, n2);
	ft_memdel((void**)&m1);
	return (res);
}
