# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 18:59:29 by edal--ce          #+#    #+#              #
#    Updated: 2021/08/05 00:28:34 by edal--ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	fdf

DIRSRC		=	src
OBJD		=	obj
INCLUDE		=	incl

INCLUDEF	=	$(INCLUDE)/header.h \
				$(INCLUDE)/test.h

SRC			=	main.c 		\
				parsing.c	\
				mlx.c 		\
				draw.c 		

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(OBJD)/%)

CFLAGS		= 	-Wall -Wextra -g -fsanitize=address #-Werror 
CFRAME		=	-framework AppKit -framework OpenGL

CC			=	clang
RM			=	rm -f

MLX_OS		=	minilibx_macos
LIB 		= 	libmlx.a


$(NAME)		:	$(LIB) $(OBJD) $(OBJS) $(INCLUDEF)
				$(CC) -I ./$(INCLUDE) -I ./$(MLX_OS) $(LIB) $(CFLAGS) $(CFRAME) $(OBJS) -o $(NAME) 

$(OBJD)		:
				@mkdir $(OBJD)

$(OBJD)/%.o	:	$(DIRSRC)/%.c 
				$(CC) -I ./$(INCLUDE) -I ./$(INCLUDE) $(CFLAGS) -o $@ -c $<

$(LIB)			:
				$(MAKE) -C $(MLX_OS)
				cp $(MLX_OS)/$(LIB) ./.

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				
				$(RM) $(NAME) $(LIB)


bonus		:	all

re			:	fclean all

.PHONY		:	all clean re fclean
