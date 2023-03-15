/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 04:15:54 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/15 09:19:50 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	offscreen(int x, int y)
{
	if (x <= 0 || x >= WIN_WIDTH)
		return (1);
	if (y <= 0 || y >= WIN_HEIGHT)
		return (1);
	return (0);
}

void	map_points(t_point *this, t_fdf *fdf)
{
	double	x_upd;
	double	y_upd;
	t_point	tmp;

	init_tpoint(&tmp, this->x, this->y, this->z);
	if (fdf->camera.iso == 1)
	{
		x_upd = (tmp.x - tmp.y) * cos(RAD_ANGLE_2);
		y_upd = -(tmp.z) + (tmp.x + tmp.y) * sin(RAD_ANGLE_2);
	}
	else if (fdf->camera.iso == 2)
	{
		x_upd = tmp.x;
		y_upd = tmp.y;
	}
	else
	{
		x_upd = tmp.x;
		y_upd = -(tmp.z);
	}
	this->x = (int)round(x_upd) + fdf->camera.x_offset;
	this->y = (int)round(y_upd) + fdf->camera.y_offset;
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (offscreen(x, y))
		return ;
	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_background(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(fdf, x, y, 0x00);
			x++;
		}
		y++;
	}
}
