/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:27:39 by edal--ce          #+#    #+#             */
/*   Updated: 2021/08/02 13:44:07 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"


void			p_px(t_contr *contr, int x, int y, int color)
{
	char	*dst;
	t_img	img;

	img = contr->img;
	dst = img.addr + (y * img.length + x * (img.bpp / 8));
	*(unsigned int*)dst = (unsigned int)color;
}


void			print_image(t_contr *contr, int x, int y)
{
	mlx_clear_window(contr->mlx, contr->win_ptr);
	mlx_put_image_to_window(contr->mlx, contr->win_ptr,
	(contr->img).img, x, y);
	mlx_destroy_image(contr->mlx, contr->img.img);
	contr->img.img = mlx_new_image(contr->mlx, XRES, YRES);
	contr->img.addr = mlx_get_data_addr(contr->img.img, &(contr->img.bpp),
		&(contr->img.length), &(contr->img.endian));
}

int		loop_(void *params)
{
	t_contr *contr;

	contr = (t_contr*)params;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			p_px(contr, i, j, 0xFF0000);
		}
	}
	print_image((t_contr*)params, 0, 0);
	return (0);
}

void run(t_contr *contr)
{
	contr->mlx = mlx_init();
	
	contr->win_ptr = mlx_new_window(contr->mlx, XRES, YRES,
		"fdf");
	t_img image;
	image.img = mlx_new_image(contr->mlx, XRES, YRES);
	image.addr = mlx_get_data_addr(image.img, &(image.bpp), &(image.length),
		&(image.endian));
	contr->img = image;

	mlx_loop_hook(contr->mlx, loop_, (void *)contr);
}