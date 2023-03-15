/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:31:31 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/15 10:03:52 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_fdf	*fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx && free_fdf(fdf))
		exit_on_error(ERR_MLX);
	ft_printf(C_GRN "MLX init: All good\n" C_RESET);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "Fdf");
	if (!fdf->win && free_fdf(fdf))
		exit_on_error(ERR_WIN);
	ft_printf(C_GRN "WIN init: All good\n" C_RESET);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img && free_fdf(fdf))
		exit_on_error(ERR_IMG);
	ft_printf(C_GRN "IMG init: All good\n" C_RESET);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->line_length, &fdf->endian);
	ft_printf(C_GRN "ADDR init: All good\n" C_RESET);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->map_i.z_depth = 1;
	fdf->map_i.map_h = 0;
	fdf->camera.iso = 1;
	fdf->camera.zoom = 1.0;
	fdf->camera.x_offset = 0;
	fdf->camera.y_offset = 0;
	fdf->camera.xx = 0.0;
	fdf->camera.yy = 0.0;
	fdf->camera.zz = 0.0;
	ft_printf(C_GRN "FDF init: All good\n" C_RESET);
}

void	init_camera(t_fdf *fdf)
{
	int	width;
	int	height;
	int	depth_h;
	int	depth_w;

	width = (fdf->map_i.map_w + fdf->map_i.map_h) * cos(RAD_ANGLE_2);
	height = (int) find_diff(fdf->map_i.z_max, fdf->map_i.z_min);
	height += (fdf->map_i.map_h + fdf->map_i.map_w) * sin(RAD_ANGLE_2);
	depth_h = round(WIN_HEIGHT / (float) height);
	depth_w = round(WIN_WIDTH / (float) width);
	if (depth_h > depth_w)
		fdf->map_i.z_depth = depth_w;
	else
		fdf->map_i.z_depth = depth_h;
	width *= fdf->map_i.z_depth;
	height *= fdf->map_i.z_depth;
	fdf->camera.x_offset = WIN_WIDTH / 2;
	fdf->camera.y_offset = 100 + height / 2;
	ft_printf(C_GRN "CAMERA init: All good\n" C_RESET);
}

int	main(int argc, char **argv)
{
	t_fdf		fdf;

	(void)argv;
	if (argc == 2)
	{
		ft_printf(C_RED "---------- V1 FINAL ----------\n" C_RESET);
		init_fdf(&fdf);
		init_map(argv[1], &fdf);
		ft_printf(C_GRN "MAP init: success\n" C_RESET);
		ft_printf(C_CYN "Map_w = %d, map_h = %d, z_min = %d, z_max = %d\n" \
		C_RESET, \
		fdf.map_i.map_w, fdf.map_i.map_h, fdf.map_i.z_min, fdf.map_i.z_max);
		init_mlx(&fdf);
		init_camera(&fdf);
		register_hooks(&fdf);
		draw_map(&fdf);
		mlx_loop(fdf.mlx);
	}
	exit_on_error(ERR_ARGS);
	return (0);
}
