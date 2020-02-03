/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:23:21 by dkathlee          #+#    #+#             */
/*   Updated: 2019/12/30 13:29:58 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t old_size, size_t new_size)
{
	unsigned char	*res;
	size_t			i;
	size_t			o_s;
	size_t			n_s;

	if ((res = (unsigned char*)ft_memalloc(new_size)) == NULL)
		return (NULL);
	if (src == NULL)
		return ((void*)res);
	i = 0;
	o_s = old_size / sizeof(__int128_t);
	n_s = new_size / sizeof(__int128_t);
	while (i < o_s && i < n_s)
	{
		((__int128_t*)res)[i] = ((__int128_t*)src)[i];
		i++;
	}
	i *= sizeof(__int128_t);
	while (i < old_size && i < new_size)
	{
		res[i] = ((unsigned char*)src)[i];
		i++;
	}
	ft_memdel((void**)&src);
	return ((void*)res);
}
