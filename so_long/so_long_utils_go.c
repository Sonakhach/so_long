/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_go.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:54:32 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/02 12:10:07 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_iner_up(int x, int y, t_vars *vars)
{
	if (vars->matrix[y - 1][x] == 'E' && vars->sum != 0)
	{
		vars->y = (y - 1) * 100;
		vars->x = x * 100;
		fun5(vars);
		vars->matrix[y - 1][x] = 'E';
	}
	else
	{
		vars->matrix[y][x] = '0';
		vars->y = y * 100;
		vars->x = x * 100;
		fun3(vars);
		vars->matrix[y - 1][x] = 'P';
		vars->y = (y - 1) * 100;
		vars->x = x * 100;
		fun3(vars);
		fun2(vars);
		vars->count++;
		ft_printf("%d\n", vars->count);
	}
}

void	go_iner_down(int x, int y, t_vars *vars)
{
	if (vars->matrix[y + 1][x] == 'E' && vars->sum != 0)
	{
		vars->y = (y + 1) * 100;
		vars->x = x * 100;
		fun5(vars);
		vars->matrix[y + 1][x] = 'E';
	}
	else
	{
		vars->matrix[y][x] = '0';
		vars->y = y * 100;
		vars->x = x * 100;
		fun3(vars);
		vars->matrix[y + 1][x] = 'P';
		vars->y = (y + 1) * 100;
		vars->x = x * 100;
		fun3(vars);
		fun2(vars);
		vars->count++;
		ft_printf("%d\n", vars->count);
	}
}

void	go_iner_right(int x, int y, t_vars *vars)
{
	if (vars->sum != 0 && vars->matrix[y][x + 1] == 'E')
	{
		vars->y = y * 100;
		vars->x = x * 100;
		fun5(vars);
		vars->matrix[y][x] = 'E';
	}
	else
	{
		vars->matrix[y][x] = '0';
		vars->y = y * 100;
		vars->x = x * 100;
		fun3(vars);
		vars->matrix[y][x + 1] = 'P';
		vars->y = y * 100;
		vars->x = (x + 1) * 100;
		fun3(vars);
		fun2(vars);
		vars->count++;
		ft_printf("%d\n", vars->count);
	}
}

void	go_iner_left(int x, int y, t_vars *vars)
{
	if (vars->sum != 0 && vars->matrix[y][x - 1] == 'E')
	{
		vars->y = y * 100;
		vars->x = (x - 1) * 100;
		fun5(vars);
		vars->matrix[y][x - 1] = 'E';
	}
	else
	{
		vars->matrix[y][x] = '0';
		vars->y = y * 100;
		vars->x = x * 100;
		fun3(vars);
		vars->matrix[y][x - 1] = 'P';
		vars->y = y * 100;
		vars->x = (x - 1) * 100;
		fun3(vars);
		fun2(vars);
		vars->count++;
		ft_printf("%d\n", vars->count);
	}
}
