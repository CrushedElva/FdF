/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:05:26 by celva             #+#    #+#             */
/*   Updated: 2019/11/19 16:12:22 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_del(char const *s1, char const *s2)
{
	char *res;

	res = ft_strjoin(s1, s2);
	ft_memdel((void**)&s1);
	return (res);
}
