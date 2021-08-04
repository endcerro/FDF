# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 18:59:29 by edal--ce          #+#    #+#              #
#    Updated: 2021/08/05 00:21:17 by edal--ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	fdf

DIRSRC		=	src
OBJD		=	obj
INCLUDE		=	incl


# INCLUDEF	=	$(INCLUDE/:.h)

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
ECHO		=	echo
LIB 		= 	libmlx.a
MLX_OS		=	minilibx_macos

$(NAME)		:	$(LIB) $(OBJD) $(OBJS) $(INCLUDEF)
				$(CC) -I ./$(INCLUDE) -I ./$(MLX_OS) $(LIB) $(CFLAGS) $(CFRAME) $(OBJS) -o $(NAME) 

$(OBJD)		:
				@mkdir $(OBJD)

$(OBJD)/%.o	:	$(DIRSRC)/%.c 
				$(CC) -I ./$(INCLUDE) -I ./$(INCLUDE) $(CFLAGS) -o $@ -c $<

$(LIB)			:
				$(MAKE) -C $(MLX_OS)
				cp $(MLX_OS)/libmlx.a ./.

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				
				$(RM) -rf $(NAME) $(LIB)


bonus		:	all

re			:	fclean all

.PHONY		:	all clean re fclean
