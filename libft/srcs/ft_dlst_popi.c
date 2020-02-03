/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_popi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:25:15 by dkathlee          #+#    #+#             */
/*   Updated: 2019/10/09 14:17:16 by dkathlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlst_popi(t_dlist **dlst, size_t i)
{
	t_dlist	*tmp;

	if (dlst == NULL)
		return (NULL);
	if (i == 0)
	{
		tmp = *dlst;
		*dlst = (*dlst)->next;
		(*dlst)->prev = NULL;
		return (tmp);
	}
	tmp = *dlst;
	while (i-- > 0)
	{
		if (tmp->next == NULL)
			return (0);
		tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	return (tmp);
}
