/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:30:30 by celva             #+#    #+#             */
/*   Updated: 2020/01/13 12:13:31 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(cl_int err, char *str)
{
	ft_printf("%s error: %d\n", str, err);
	exit(0);
}

char		*read_cl(char *fname)
{
	int		fd;
	int		gnl;
	char	*res;
	char	*str;

	if ((fd = open(fname, O_RDONLY)) == -1)
		return (NULL);
	res = ft_memalloc(1);
	while ((gnl = get_next_line(fd, &str)) != 0)
	{
		if (gnl == -1)
			return (NULL);
		res = ft_strjoin_del(res, "\n");
		res = ft_strjoin_del(res, str);
		ft_memdel((void**)&str);
	}
	return (res);
}

static void	init_cl3(t_all *a)
{
	cl_int	err;

	a->opencl.pxs_mem = clCreateBuffer(a->opencl.context, CL_MEM_READ_WRITE,
								(X_WIN * Y_WIN * 4), NULL, &err);
	a->opencl.p_mem = clCreateBuffer(a->opencl.context, CL_MEM_READ_ONLY,
			(a->map.x * a->map.y * (sizeof(t_point_3d))), NULL, &err);
	if (err != CL_SUCCESS)
		error(err, "Create buffer");
	err = clEnqueueWriteBuffer(a->opencl.command, a->opencl.p_mem, CL_TRUE, 0,
		sizeof(t_point_3d) * a->map.x * a->map.y, a->map.pts, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		error(err, "Write buffer");
}

static void	init_cl2(t_all *a)
{
	cl_int	err;
	char	buf[1000000];

	err = clBuildProgram(a->opencl.program, 0, NULL, NULL, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		err = clGetProgramBuildInfo(a->opencl.program, a->opencl.device,
							CL_PROGRAM_BUILD_LOG, 1000000, buf, NULL);
		if (err == CL_SUCCESS)
		{
			ft_printf("Compiler error:\n%s\n", buf);
			exit(0);
		}
		else
			error(err, "Get programm build info");
	}
	a->opencl.kernel = clCreateKernel(a->opencl.program, "drawing", &err);
	if (err != CL_SUCCESS)
		error(err, "Create Kernel");
	init_cl3(a);
}

void		init_cl(t_all *a)
{
	cl_int	err;
	char	*progr;

	a->opencl.context = clCreateContextFromType(NULL, CL_DEVICE_TYPE_GPU,
										NULL, NULL, &err);
	if (err != CL_SUCCESS)
		error(err, "Create context");
	err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1,
								&(a->opencl.device), NULL);
	if (err != CL_SUCCESS)
		error(err, "Get device");
	a->opencl.command = clCreateCommandQueue(a->opencl.context,
										a->opencl.device, 0, &err);
	if (err != CL_SUCCESS)
		error(err, "Create command queue");
	progr = read_cl("main.cl");
	a->opencl.program = clCreateProgramWithSource(a->opencl.context, 1,
										(const char**)&progr, NULL, &err);
	if (err != CL_SUCCESS)
		error(err, "Create program");
	ft_memdel((void**)&progr);
	init_cl2(a);
}
