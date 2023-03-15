/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 04:14:23 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/15 09:19:22 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_line(int x, int y, t_fdf *fdf)
{
	t_point		start;
	t_point		fin;

	init_tpoint(&start,
		(x - fdf->map_i.map_w / 2) * fdf->map_i.z_depth,
		(y - fdf->map_i.map_h / 2) * fdf->map_i.z_depth,
		fdf->map_i.map[y][x] * fdf->map_i.z_depth);
	init_tpoint(&fin,
		((x + 1) - fdf->map_i.map_w / 2) * fdf->map_i.z_depth,
		(y - fdf->map_i.map_h / 2) * fdf->map_i.z_depth,
		fdf->map_i.map[y][x + 1] * fdf->map_i.z_depth);
	start.color = fdf->map_i.color[y][x];
	fin.color = fdf->map_i.color[y][x + 1];
	if (start.color == -1)
		start.color = COL_VIOLET;
	if (fin.color == -1)
		fin.color = COL_VIOLET;
	rotate_point(&start, fdf);
	rotate_point(&fin, fdf);
	map_points(&start, fdf);
	map_points(&fin, fdf);
	draw_line(fdf, &start, &fin);
}

void	draw_vertical_line(int x, int y, t_fdf *fdf)
{
	t_point		start;
	t_point		fin;

	init_tpoint(&start,
		(x - fdf->map_i.map_w / 2) * fdf->map_i.z_depth,
		(y - fdf->map_i.map_h / 2) * fdf->map_i.z_depth,
		fdf->map_i.map[y][x] * fdf->map_i.z_depth);
	init_tpoint(&fin,
		(x - fdf->map_i.map_w / 2) * fdf->map_i.z_depth,
		((y + 1) - fdf->map_i.map_h / 2) * fdf->map_i.z_depth,
		fdf->map_i.map[y + 1][x] * fdf->map_i.z_depth);
	start.color = fdf->map_i.color[y][x];
	fin.color = fdf->map_i.color[y + 1][x];
	rotate_point(&start, fdf);
	rotate_point(&fin, fdf);
	map_points(&start, fdf);
	map_points(&fin, fdf);
	draw_line(fdf, &start, &fin);
}

static void	print_in_order(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map_i.map_h)
	{
		x = 0;
		while (x < fdf->map_i.map_w)
		{
			if (x < (fdf->map_i.map_w - 1))
				draw_horizontal_line(x, y, fdf);
			if (y < (fdf->map_i.map_h - 1))
				draw_vertical_line(x, y, fdf);
			x++;
		}
		y++;
	}
}

void	draw_map(t_fdf *fdf)
{
	fill_background(fdf);
	print_in_order(fdf);
	draw_ui(fdf);
}
