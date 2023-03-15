/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:06:06 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/15 11:06:32 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bonus_plus(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map_i.map_h)
	{
		x = 0;
		while (x < fdf->map_i.map_w)
		{
			if (fdf->map_i.map[y][x] != 0)
				fdf->map_i.map[y][x] += 1;
			x++;
		}
		y++;
	}
}

void	bonus_minus(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map_i.map_h)
	{
		x = 0;
		while (x < fdf->map_i.map_w)
		{
			if (fdf->map_i.map[y][x] != 0)
				fdf->map_i.map[y][x] -= 1;
			x++;
		}
		y++;
	}
}
