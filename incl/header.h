/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:01:59 by edal--ce          #+#    #+#             */
/*   Updated: 2021/08/02 12:42:34 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
#define HEADER_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_node
{
	int 			height;
	unsigned int 	R;
	unsigned int 	G;
	unsigned int 	B;
} t_node;

typedef struct s_contr
{
	void			*mlx;
	// char 			**map;
	t_node 			**map;
	unsigned int  	map_h;
	unsigned int  	map_w;		
} t_contr;

//BASIC FUNS
int parsing(t_contr *contr, char *path);

#endif