/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:31:19 by celva             #+#    #+#             */
/*   Updated: 2019/12/02 11:34:11 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 32

typedef struct	s_list_fd
{
	char				*str;
	int					fd;
	struct s_list_fd	*next;
}				t_list_fd;

int				get_next_line(const int fd, char **line);

#endif
