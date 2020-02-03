/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:28:42 by celva             #+#    #+#             */
/*   Updated: 2019/09/25 11:29:46 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buf(int fd, t_list_fd *lst)
{
	char	buf[BUFF_SIZE + 1];
	int		r;
	char	*tmp;

	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = lst->str;
		lst->str = ft_strjoin(lst->str, buf);
		ft_memdel((void**)&tmp);
		if (ft_strchr(buf, '\n') != NULL)
			return (1);
	}
	if (ft_strlen(lst->str) != 0)
		return (2);
	return (0);
}

static int	w_file(int fd, char **line, t_list_fd *lst)
{
	int		rb;
	char	*tmp;

	if ((ft_strchr(lst->str, '\n') != NULL) || (rb = read_buf(fd, lst)) == 1)
	{
		*line = ft_strsub(lst->str, 0,
							(ft_strchr(lst->str, '\n') - lst->str));
		tmp = lst->str;
		lst->str = ft_strsub((ft_strchr(lst->str, '\n') + 1), 0,
				(ft_strchr(lst->str, '\0') - ft_strchr(lst->str, '\n')));
		ft_memdel((void**)&tmp);
	}
	else if (rb == 2)
	{
		*line = ft_strsub(lst->str, 0, (ft_strlen(lst->str) + 1));
		lst->str = NULL;
	}
	else
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list_fd	*lst;
	t_list_fd			*new;

	if (line == NULL || fd < 0 || read(fd, *line, 0) == -1)
		return (-1);
	new = lst;
	*line = NULL;
	while (new != NULL)
	{
		if (new->fd == fd)
			break ;
		new = new->next;
	}
	if (new == NULL)
	{
		new = (t_list_fd*)malloc(sizeof(t_list_fd));
		if (new == NULL)
			return (-1);
		new->str = ft_strnew(0);
		new->next = lst;
		new->fd = fd;
		lst = new;
	}
	return (w_file(fd, line, new));
}
