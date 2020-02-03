/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:41:32 by celva             #+#    #+#             */
/*   Updated: 2020/01/13 14:41:29 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color_gui(t_all *m)
{
	int i;
	int j;

	i = 0;
	while (i < Y_TXT)
	{
		j = X_WIN - X_TXT;
		while (j < X_WIN)
		{
			m->str_pxs[i * X_WIN + j].r = 180;
			m->str_pxs[i * X_WIN + j].g = 165;
			m->str_pxs[i * X_WIN + j].b = 180;
			j++;
		}
		i++;
	}
}

static void	insert_text_more(t_all *m)
{
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 320, 90000,
												"pressing the key:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1190, 320, 0, "X, Y, Z");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 340, 90000,
												"Rotate on a selected axis:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1120, 360, 0, "4/6 on the numpad");
}

void		insert_text(t_all *m)
{
	mlx_string_put(m->ptr_init, m->ptr_win, 1050, 10, 0, "Projection control:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 50, 0, "C:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1040, 50, 90000, "color change");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 70, 0, "R:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1040, 70, 90000, "reset to start");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 90, 0, "Mouse wheel or +/-:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1210, 90, 90000, "scale");
	mlx_string_put(m->ptr_init, m->ptr_win, 1050, 120, 0,
												"Projection change: ");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 140, 0, "P:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1040, 140, 90000,
												"parallel projection");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 160, 0, "I:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1040, 160, 90000, "iso projection");
	mlx_string_put(m->ptr_init, m->ptr_win, 1050, 190, 0, "Axial movement:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 210, 90000, "X:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1040, 210, 0, "up/down arrow");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 230, 90000, "Y:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1040, 230, 0, "right/left arrow");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 250, 90000, "Z:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1040, 250, 0, "8/2 on the numpad");
	mlx_string_put(m->ptr_init, m->ptr_win, 1050, 280, 0, "Axial rotation:");
	mlx_string_put(m->ptr_init, m->ptr_win, 1010, 300, 90000,
												"Select the rotation axis by");
	insert_text_more(m);
}

int			close_wind(void *param)
{
	(void)param;
	exit(0);
}

int			main(int ac, char **av)
{
	t_all	*m;

	if (ac == 1)
	{
		ft_printf("%s\n", "usage:	./fdf file_name");
		return (0);
	}
	m = init_fdf(av[1]);
	if (m == NULL)
	{
		ft_printf("File error!\n");
		return (0);
	}
	if (m == NULL)
		return (0);
	drawing_gpu(m);
	color_gui(m);
	mlx_put_image_to_window(m->ptr_init, m->ptr_win, m->ptr_img, 0, 0);
	insert_text(m);
	mlx_hook(m->ptr_win, 2, 0, &key_press, m);
	mlx_mouse_hook(m->ptr_win, &(mouse_press), m);
	mlx_hook(m->ptr_win, 17, 0, &close_wind, m);
	mlx_loop(m->ptr_init);
}
