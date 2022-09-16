/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:13:35 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/02 20:10:38 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*iner(char *map, char *map_binar, int fd)
{
	if (map[0] == '\n')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (map != NULL)
	{
		if (!map_binar)
			map_binar = ft_strdup(map);
		else
			map_binar = ft_strjoin(map_binar, map);
		map = get_next_line(fd);
		if (map == NULL)
			break ;
		free(map);
	}
	return (map_binar);
}

char	*get_string(char *av)
{
	int		fd;
	char	*map;
	char	*map_binar;
	char	*tmp;
	char	*a;

	map_binar = NULL;
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Something went wrong..\n", 21);
		exit(1);
	}
	map = get_next_line(fd);
	tmp = map;
	a = iner(map, map_binar, fd);
	free(tmp);
	return (a);
}

char	**get_matrix(char *av)
{
	char	**map_matrix;
	char	*map_line;
	int		i;

	map_line = get_string(av);
	i = 1;
	map_matrix = ft_split(map_line, '\n');
	free(map_line);
	return (map_matrix);
}

void	count_colect(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->sum = 0;
	vars->plyer = 0;
	vars->e_xit = 0;
	while (vars->matrix[i])
	{
		j = 0;
		while ((vars->matrix)[i][j])
		{
			if ((vars->matrix)[i][j] == 'C')
				vars->sum++;
			if (vars->matrix[i][j] == 'P')
				vars->plyer++;
			if (vars->matrix[i][j] == 'E')
				vars->e_xit++;
			j++;
		}
		i++;
	}
}

int	plyer_cord(char **map, int c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (c == 'x')
					return (j);
				else
					return (i);
			}	
			j++;
		}
		i++;
	}
	return (0);
}
