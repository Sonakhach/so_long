/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:50:32 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/02 20:05:03 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width_height(char **map, int c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	if (c == 'x')
		return (j);
	else
		return (i);
	return (0);
}

int	cl(t_vars *vars)
{
	(void)vars;
	exit(0);
}

void	newline(char *av)
{
	int		i;
	char	*map_line;

	i = 0;
	map_line = get_string(av);
	while (map_line[i])
	{
		if (map_line[i - 1] == '\n' && map_line[i] == '\n')
		{
			write (1, "You have error", 14);
			exit (1);
		}
	i++;
	}
	free(map_line);
}

void	imaging_map(t_vars vars, int i, int j)
{
	i = 0;
	while (vars.matrix[i])
	{
		j = 0;
		while (vars.matrix[i][j])
		{
			vars.y = i * 100;
			vars.x = j * 100;
			fun3(&vars);
			if (vars.matrix[i][j] == '1')
				fun1(&vars);
			else if (vars.matrix[i][j] == '0')
				fun3(&vars);
			else if (vars.matrix[i][j] == 'C')
				fun4(&vars);
			else if (vars.matrix[i][j] == 'P')
				fun2(&vars);
			else if (vars.matrix[i][j] == 'E')
				fun5(&vars);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{		
		vars.count = 0;
		vars.matrix = get_matrix(av[1]);
		count_colect(&vars);
		newline(av[1]);
		if (!wall(&vars) || !first_last_row_error(&vars) || !rectangular(&vars)
			|| vars.plyer != 1 || vars.e_xit < 1 || vars.sum < 1
			|| !path_error(av[1]) || !only5char(&vars))
		{
			printf("Somthing went wrong\n");
			exit(1);
		}
		vars.mlx = mlx_init();
		vars.mlx_win = mlx_new_window(vars.mlx,
				(width_height(vars.matrix, 'x') * 100),
				(width_height(vars.matrix, 'y') * 100), "Hello delphin!");
		imaging_map(vars, 0, 0);
		mlx_hook(vars.mlx_win, 17, 1L << 0, cl, &vars);
		mlx_key_hook(vars.mlx_win, key_hook1, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
