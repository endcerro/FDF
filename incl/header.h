/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:01:59 by edal--ce          #+#    #+#             */
/*   Updated: 2021/08/05 00:13:55 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
#define HEADER_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define XRES 500
#define YRES 500

typedef struct s_node
{
	int 			height;
	unsigned int 	color;
	unsigned int 	R;
	unsigned int 	G; 
	unsigned int 	B;
} t_node;

typedef struct s_dot
{
	int 			x;
	int 			y;
	int 			color;
} 	t_dot;

typedef struct	s_img
{
	int				bpp;
	int				length;
	int				endian;
	void			*img;
	char			*addr;
}				t_img;

typedef struct s_contr
{
	void			*mlx;
	void 			*win_ptr;
	// void 			*image;
	// char 			**map;
	t_img			img;
	t_node 			**map;
	unsigned int  	map_h;
	unsigned int  	map_w;		
} t_contr;

//BASIC FUNS
int parsing(t_contr *contr, char *path);

//MLX FUNS
void	run(t_contr *contr);
void	p_px(t_contr *contr, int x, int y, int color);
//HOOKS
int		mouse_(int btn, int x, int y, t_contr *contr);


#endif