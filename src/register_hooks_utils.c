/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:55:04 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/15 11:04:03 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	translate_map(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_DOWN)
		fdf->camera.y_offset -= 30;
	if (keycode == KEY_UP)
		fdf->camera.y_offset += 30;
	if (keycode == KEY_RIGHT)
		fdf->camera.x_offset -= 30;
	if (keycode == KEY_LEFT)
		fdf->camera.x_offset += 30;
}

static void	zoom_in_out(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_MINUS && fdf->map_i.z_depth > 0)
		fdf->map_i.z_depth -= 1;
	if (keycode == KEY_PLUS)
		fdf->map_i.z_depth += 1;
	if (keycode == KEY_Q)
		bonus_plus(fdf);
	if (keycode == KEY_E)
		bonus_minus(fdf);
}

static void	rotate_map(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_1)
		fdf->camera.xx -= 0.2;
	if (keycode == KEY_2)
		fdf->camera.xx += 0.2;
	if (keycode == KEY_3)
		fdf->camera.yy -= 0.2;
	if (keycode == KEY_4)
		fdf->camera.yy += 0.2;
	if (keycode == KEY_5)
		fdf->camera.zz -= 0.2;
	if (keycode == KEY_6)
		fdf->camera.zz += 0.2;
}

static void	projection(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_S)
		fdf->camera.iso = 0;
	if (keycode == KEY_I)
		fdf->camera.iso = 1;
	if (keycode == KEY_T)
		fdf->camera.iso = 2;
	fdf->camera.xx = 0.0;
	fdf->camera.yy = 0.0;
	fdf->camera.zz = 0.0;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT \
	|| keycode == KEY_UP || keycode == KEY_DOWN)
		translate_map(keycode, fdf);
	else if (keycode == KEY_MINUS || keycode == KEY_PLUS \
	|| keycode == KEY_Q || keycode == KEY_E)
		zoom_in_out(keycode, fdf);
	else if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3
		|| keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6)
		rotate_map(keycode, fdf);
	else if (keycode == KEY_T || keycode == KEY_I || keycode == KEY_S)
		projection(keycode, fdf);
	else
	{
		ft_printf("Hello from key_hook - [%d]!\n", keycode);
		return (0);
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	draw_ui(fdf);
	return (1);
}
