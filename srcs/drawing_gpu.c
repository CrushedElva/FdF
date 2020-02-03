/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_gpu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:27:47 by celva             #+#    #+#             */
/*   Updated: 2020/01/13 12:12:31 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawing_gpu2(t_all *a)
{
	cl_int	err;
	size_t	global;
	size_t	x;

	err = clGetKernelWorkGroupInfo(a->opencl.kernel, a->opencl.device,
		CL_KERNEL_WORK_GROUP_SIZE, sizeof(size_t), &x, NULL);
	if (err != CL_SUCCESS)
		error(err, "Get work group info");
	global = a->map.x * a->map.y * sizeof(t_point_3d);
	global += x - (global % x);
	err = clEnqueueNDRangeKernel(a->opencl.command, a->opencl.kernel, 1,
				NULL, &global, &x, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		error(err, "Range Kernel");
	clFinish(a->opencl.command);
	clEnqueueReadBuffer(a->opencl.command, a->opencl.pxs_mem, CL_TRUE, 0,
			X_WIN * Y_WIN * 4, a->str_pxs, 0, NULL, NULL);
	insert_text(a);
}

void		drawing_gpu(t_all *a)
{
	cl_int	err;

	clear(a);
	err = clSetKernelArg(a->opencl.kernel, 0, sizeof(int), &a->map.y);
	err |= clSetKernelArg(a->opencl.kernel, 1, sizeof(int), &a->map.x);
	err |= clSetKernelArg(a->opencl.kernel, 2, sizeof(double), &a->map.z_max.z);
	err |= clSetKernelArg(a->opencl.kernel, 3, sizeof(cl_mem),
													&a->opencl.p_mem);
	err |= clSetKernelArg(a->opencl.kernel, 4, sizeof(t_transform), &a->t);
	err |= clSetKernelArg(a->opencl.kernel, 5, sizeof(int), &a->size_l);
	err |= clSetKernelArg(a->opencl.kernel, 6, sizeof(cl_mem),
													&a->opencl.pxs_mem);
	err |= clSetKernelArg(a->opencl.kernel, 7, sizeof(int), &a->pr);
	if (err != CL_SUCCESS)
		error(err, "Set Kernel arg");
	err = clEnqueueWriteBuffer(a->opencl.command, a->opencl.pxs_mem, CL_TRUE,
			0, sizeof(t_color) * (X_WIN) * Y_WIN, a->str_pxs, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		error(err, "Write buffer");
	drawing_gpu2(a);
}
