/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:16:40 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/15 09:17:53 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_ui(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, \
	0xFFFF00, "Translate model : Arrow");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0xFFFF00, "zoom in out : - +");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, \
	0xFFFF00, "rotate model : 1 - 6");
}
