/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:36:44 by edal--ce          #+#    #+#             */
/*   Updated: 2021/08/05 00:15:13 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"





void freemap(t_contr *contr)
{
	for (unsigned int i = 0; i < contr->map_h; i++)
		free(contr->map[i]);
	free(contr->map);
}

 
int main(int argc, char **argv)
{
	t_contr contr;
	if (argc != 2)
		return (printf("./fdf [PATH TO MAP]\n"));
	if (parsing(&contr, argv[1]) != 0)
		return 1;
	run(&contr);
	
	freemap(&contr);
	mlx_destroy_image(contr.mlx, contr.img.img);
	mlx_destroy_window(contr.mlx, contr.win_ptr);
	free(contr.mlx);
	return 0;
}