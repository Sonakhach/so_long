/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:47:55 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/02 12:00:43 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	first_last_row_error(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->matrix[i])
	{
		j = 0;
		while (vars->matrix[i][j])
		{
			if (vars->matrix[0][j] != '1'
			|| (vars->matrix[width_height(vars->matrix, 'y') - 1][j]) != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	wall(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->matrix[i])
	{
		j = 0;
		while (vars->matrix[i][j])
		{
			if (vars->matrix[i][0] != '1'
			|| (vars->matrix[i][width_height(vars->matrix, 'x') - 1]) != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	rectangular(t_vars *vars)
{
	int	i;
	int	j;

	i = 1;
	while (vars->matrix[i])
	{
		j = 1;
		while (vars->matrix[i][j])
		{
			if ((vars->matrix[width_height(vars->matrix, 'y') - 1][j])
			!= (vars->matrix[width_height(vars->matrix, 'y') - 1][j - 1])
			|| (vars->matrix[i][width_height(vars->matrix, 'x') - 1])
			!= (vars->matrix[i - 1][width_height(vars->matrix, 'x') - 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	path_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 'r' || s[i - 2] != 'e'
		|| s[i - 3] != 'b' || s[i - 4] != '.')
		return (0);
	else
		return (1);
}

int	only5char(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->matrix[i])
	{
		j = 0;
		while (vars->matrix[i][j])
		{
			if ((vars->matrix[i][j]) != '1' && (vars->matrix[i][j]) != '0'
			&& (vars->matrix[i][j]) != 'C'
			&& (vars->matrix[i][j]) != 'E' && (vars->matrix[i][j]) != 'P' )
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
