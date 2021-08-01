# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 18:59:29 by edal--ce          #+#    #+#              #
#    Updated: 2021/08/01 19:05:40 by edal--ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

DIRSRC		=	src
OBJD		=	obj
INCLUDE		=	incl

SRC			=	main.c

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(OBJD)/%)

CFLAGS		= 	-Wall -Wextra -g -fsanitize=address #-Werror 

CC			=	clang
RM			=	rm -f
ECHO		=	echo

$(NAME)		:	LIB $(OBJD) $(OBJS)
				$(CC) -I ./$(INCLUDE) $(CFLAGS) $(OBJS) -o $(NAME) 

$(OBJD)		:
				@mkdir $(OBJD)

$(OBJD)/%.o	:	$(DIRSRC)/%.c
				$(CC) -I ./$(INCLUDE) $(CFLAGS) -o $@ -c $<

LIB			:
				$(MAKE) -C minilibx_macos
				cp minilibx_macos/libmlx.a ./.

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				
				$(RM) $(NAME)


bonus		:	all

re			:	fclean all

.PHONY		:	all clean re fclean