/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:31:20 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/02 19:47:15 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook1(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		go_up(vars);
	else if (keycode == 1 || keycode == 125)
		go_down(vars);
	else if (keycode == 0 || keycode == 123)
		go_left(vars);
	else if (keycode == 2 || keycode == 124)
		go_right(vars);
	return (0);
}

void	go_up(t_vars *vars)
{
	int	x;
	int	y;

	x = plyer_cord(vars->matrix, 'x');
	y = plyer_cord(vars->matrix, 'y');
	if (vars->matrix[y - 1][x] != '1' )
	{
		if (vars->matrix[y - 1][x] == 'C')
			(vars->sum) = vars->sum - 1;
		if (vars->sum == 0 && vars->matrix[y - 1][x] == 'E')
			exit(0);
		go_iner_up(x, y, vars);
	}
}

void	go_down(t_vars *vars)
{
	int	x;
	int	y;

	x = plyer_cord(vars->matrix, 'x');
	y = plyer_cord(vars->matrix, 'y');
	if (vars->matrix[y + 1][x] != '1')
	{
		if (vars->matrix[y + 1][x] == 'C')
			(vars->sum) = vars->sum - 1;
		if (vars->sum == 0 && vars->matrix[y + 1][x] == 'E')
			exit(0);
		go_iner_down(x, y, vars);
	}
}

void	go_right(t_vars *vars)
{
	int	x;
	int	y;

	x = plyer_cord(vars->matrix, 'x');
	y = plyer_cord(vars->matrix, 'y');
	if (vars->matrix[y][x + 1] != '1')
	{
		if (vars->matrix[y][x + 1] == 'C')
			(vars->sum)--;
		if (vars->sum == 0 && vars->matrix[y][x + 1] == 'E')
			exit(0);
		go_iner_right(x, y, vars);
	}		
}

void	go_left(t_vars *vars)
{
	int	x;
	int	y;

	x = plyer_cord(vars->matrix, 'x');
	y = plyer_cord(vars->matrix, 'y');
	if (vars->matrix[y][x - 1] != '1')
	{
		if (vars->matrix[y][x - 1] == 'C')
			(vars->sum)--;
		if (vars->sum == 0 && vars->matrix[y][x - 1] == 'E')
			exit(0);
		go_iner_left(x, y, vars);
	}
}
