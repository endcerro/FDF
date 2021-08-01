/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:37:08 by edal--ce          #+#    #+#             */
/*   Updated: 2021/08/01 21:01:31 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

char	*recurs(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*out;
	int		test;

	test = read(fd, buff, 1);
	if (test == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		out = malloc(sizeof(char) * depth + 1);
		if (out == NULL)
			return (0);
		out[depth] = 0;
		*ret = 1;
		if (buff[0] == 0)
			*ret = 0;
		return (out);
	}
	else
	{
		out = recurs(depth + 1, ret, fd);
		out[depth] = buff[0];
	}
	return (out);
}

int	get_next_line(int fd, char **out)
{
	int	ret;

	ret = 1;
	*out = recurs(0, &ret, fd);
	return (ret);
}

void parsing_recurs(t_contr *contr, int fd, int depth)
{
	char *tmp;

	if (get_next_line(fd, &tmp))
	{
		parsing_recurs(contr, fd, depth + 1);
	}
	else
	{
		contr->map = malloc(sizeof(char *) * (depth + 1));
		contr->map[depth] = 0;
		return ;
	}
	contr->map[depth] = tmp;
}

void test(t_contr *contr)
{
	int i = 0;
	while (contr->map[i])
	{
		printf("%s\n", contr->map[i++]);
	}
}

int	parsing(t_contr *contr, char *path)
{
	char 	**output;
	int 	fd;
	int 	depth;

	depth = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (printf("Unable to open file at path %s\n", path));
	parsing_recurs(contr, fd, 0);
	test(contr);
	return 0;
}

