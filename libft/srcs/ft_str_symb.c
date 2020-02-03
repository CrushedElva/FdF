/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_symb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:44:27 by celva             #+#    #+#             */
/*   Updated: 2019/11/15 12:44:30 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_symb(char *str, char *sym_check)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(sym_check, str[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}
