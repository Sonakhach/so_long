/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:53:35 by sokhacha          #+#    #+#             */
/*   Updated: 2022/09/02 12:01:57 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fun1(t_vars *vars)
{
	void	*img1;
	char	*r_path1;
	int		img_width;
	int		img_height;

	r_path1 = "./img/img/grass.xpm";
	img1 = mlx_xpm_file_to_image(vars->mlx, r_path1, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img1, vars->x, vars->y);
}

void	fun2(t_vars *vars)
{
	void	*img2;
	char	*r_path2;
	int		img_width;
	int		img_height;

	r_path2 = "./img/img/delphin.xpm";
	img2 = mlx_xpm_file_to_image(vars->mlx, r_path2, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img2, vars->x, vars->y);
}

void	fun3(t_vars *vars)
{
	void	*img3;
	char	*r_path3;
	int		img_width;
	int		img_height;

	r_path3 = "./img/img/sea.xpm";
	img3 = mlx_xpm_file_to_image(vars->mlx, r_path3, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img3, vars->x, vars->y);
}

void	fun4(t_vars *vars)
{
	void	*img4;
	char	*r_path4;
	int		img_width;
	int		img_height;

	r_path4 = "./img/img/fish.xpm";
	img4 = mlx_xpm_file_to_image(vars->mlx, r_path4, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img4, vars->x, vars->y);
}

void	fun5(t_vars *vars)
{
	void	*img5;
	char	*r_path5;
	int		img_width;
	int		img_height;

	r_path5 = "./img/img/exit.xpm";
	img5 = mlx_xpm_file_to_image(vars->mlx, r_path5, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img5, vars->x, vars->y);
}
