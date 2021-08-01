/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:36:44 by edal--ce          #+#    #+#             */
/*   Updated: 2021/08/01 21:03:11 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"


int main(int argc, char **argv)
{
	t_contr contr;
	if (argc != 2)
		return (printf("./fdf [PATH TO MAP]\n"));
	if (parsing(&contr, argv[1]))
		return 1;

	// contr.mlx = mlx_init();
	free(contr.mlx);
	for (unsigned int i = 0; i < contr.map_h; i++)
		free(contr.map[i]);
	free(contr.map);
	return 0;
}