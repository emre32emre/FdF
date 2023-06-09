/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:43:10 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/15 11:05:49 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	win_close(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		free_fdf(fdf);
		ft_printf("You pressed ESC. Exiting program, bye!\n");
		exit (1);
	}
	return (0);
}

int	win_close_x(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free_fdf(fdf);
	ft_printf("You clicked [x] button. Exiting program, bye!\n");
	exit (1);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	(void) fdf;
	ft_printf("Mouse (button = %d) pressed - (%d, %d) !\n", button, x, y);
	return (1);
}

void	register_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, 2, 1L << 0, win_close, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, win_close_x, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
}
