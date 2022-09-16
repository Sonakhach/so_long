/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:23:32 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/02 11:46:26 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	char	**matrix;
	int		x;
	int		y;
	int		count;
	int		sum;
	int		plyer;
	int		e_xit;
}	t_vars;
void	imaging_map(t_vars vars, int i, int j);
void	count_colect(t_vars *vars);
char	*get_string(char *av);
char	**get_matrix(char *av);
int		key_hook1(int keycode, t_vars *vars);
int		plyer_cord(char **map, int c);
void	go_up(t_vars *vars);
void	go_down(t_vars *vars);
void	go_left(t_vars *vars);
void	go_right(t_vars *vars);
void	fun1(t_vars *vars);
void	fun2(t_vars *vars);
void	fun3(t_vars *vars);
void	fun4(t_vars *vars);
void	fun5(t_vars *vars);
int		wall(t_vars *vars);
int		rectangular(t_vars *vars);
int		first_last_row_error(t_vars *vars);
int		path_error(char *s);
int		width_height(char **map, int c);
int		only5char(t_vars *vars);
void	newline(char *av);
void	check_path(char *path);
void	go_iner_up(int x, int y, t_vars *vars);
void	go_iner_down(int x, int y, t_vars *vars);
void	go_iner_right(int x, int y, t_vars *vars);
void	go_iner_left(int x, int y, t_vars *vars);
int		cl(t_vars *vars);
char	**ft_split(char *s, char c);

#endif
