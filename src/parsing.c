/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 20:37:08 by edal--ce          #+#    #+#             */
/*   Updated: 2021/08/02 12:55:28 by edal--ce         ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c < 58 && c > 47)
		return (1);
	return (0);
}

int		ft_isspace(char in)
{
	if (in == ' ' || in == '	' || in == '\n' || in == '\t' ||
		in == '\v' || in == '\f' || in == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *in)
{
	int pos;
	int nb;

	nb = 0;
	pos = 1;
	while (*in && ft_isspace(*in))
		++in;
	if (*in == '-')
	{
		pos = -1;
		++in;
	}
	else if (*in == '+')
		++in;
	while (ft_isdigit(*in))
		nb = nb * 10 + (*(in++) - '0');
	return (nb * pos);
}

int getlen(char *line)
{
	int amt;
	int i;

	i = 0;
	amt = 0;

	while(line[i])
	{
		while(line[i] && (line[i] == '-' || ft_isdigit(line[i])))
			++i;
		++amt;
		if (line[i] && line[i] == ',')
		{
			// i += 9; 
			//Case where RGB is supplied
		}
		while(line[i] && ft_isspace(line[i]))
			++i;
	}
	// printf("amt %d for %s\n", amt, line);
	return (amt);
}

void printmap(t_contr *contr, int rgb)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while(contr->map[i])
	{
		while(j < contr->map_w)
		{
			printf("%d", contr->map[i][j].height);
			if (rgb)
				printf("[%d%d%d]",contr->map[i][j].R, contr->map[i][j].G, contr->map[i][j].B);
			++j;
		}
		printf("\n");
		++i;
		j = 0;
	}
}

void setrgb(t_node *node, char *rgb)
{
	// if (rgb == NULL)
	// {
		node->R = 0;
		node->G = 0;
		node->B = 0;
	// }
}

t_node *parse_line(char *tmp, t_contr *contr)
{
	static int 	len = -1;
	int 		i = 0;
	int 		j = 0;
	t_node 		*ret;

	if (len == -1)
		len = getlen(tmp);
	contr->map_w = len;
	ret = malloc(sizeof(t_node) * len);
	if (ret == NULL)
		return 0;
	// printf("For line %s\n", tmp);
	while(tmp[i])
	{
		ret[j++].height = ft_atoi(tmp + i);
		while(ft_isdigit(tmp[i]) || tmp[i] == '-')
			++i;
		if (tmp[i] == ',')
		{
			//Skip RGB for now
			// i += 9;
		}
		else
		{
			setrgb(&(ret[j - 1]), NULL);
		}
		while(ft_isspace(tmp[i]))
			++i;
	}


	return (ret);
}

int parsing_recurs(t_contr *contr, int fd, int depth)
{
	char *tmp;

	if (get_next_line(fd, &tmp))
	{
		if (parsing_recurs(contr, fd, depth + 1))
		{
			free(tmp);
			return (1);
		}
	}
	else
	{
		free(tmp);
		contr->map = malloc(sizeof(t_node *) * (depth + 1));
		if (contr->map == NULL)
			return (1);
		contr->map[depth] = 0;
		return (0);
	}
	contr->map[depth] = parse_line(tmp, contr);
	free(tmp);
	if (contr->map[depth] == NULL)
		return (1);
	
	return (0);
}


int	parsing(t_contr *contr, char *path)
{
	int 	fd;
	int 	depth;

	depth = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (printf("Unable to open file at path %s\n", path));
	parsing_recurs(contr, fd, 0);
	printmap(contr, 1);
	return 0;
}

