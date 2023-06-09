/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:33:27 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/15 11:04:28 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libmlx/mlx.h"
# include "../lib/libft/libft.h"

# include "key_code.h"
# include "error_messages.h"

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH		1200
# define WIN_HEIGHT		800
# define IMG_WIDTH		1000
# define IMG_HEIGHT		700
# define RAD_ANGLE		0.46365
# define RAD_ANGLE_2	0.523599

# define COL_RED		0x00D13632
# define COL_ORANGE		0x00E2571E
# define COL_YELLOW		0x00CDB924
# define COL_GREEN		0x00479E1B
# define COL_BLUE		0x001D829E
# define COL_VIOLET		0x00503FA9
# define COL_BLACK		0x002B2B2A
# define COL_UI			0xFFFF00

typedef struct s_map {
	int			map_h;
	int			map_w;
	int			z_depth;
	int			z_min;
	int			z_max;
	int			**map;
	int			**color;
}				t_map;

typedef struct s_camera {
	int			iso;
	int			x_offset;
	int			y_offset;
	double		xx;
	double		yy;
	double		zz;
	double		zoom;
}				t_camera;

typedef struct s_fdf {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_camera	camera;
	t_map		map_i;
}				t_fdf;

typedef struct s_point {
	int					x;
	int					y;
	int					z;
	int					color;
	struct s_point		*next;
}						t_point;

typedef struct s_pair {
	double		x;
	double		y;
}				t_pair;

/* Init program functions */
void	init_map(char *map_file, t_fdf *fdf);
void	register_hooks(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);

/* Init map functions */
void	list_to_arr(t_point *flat_map, t_fdf *fdf);
void	map_to_arr(t_point *flat_map, t_fdf *fdf);
void	color_to_arr(t_point *flat_map, t_fdf *fdf);
void	update_colors(t_fdf *fdf);

/* Error management */
void	exit_on_error(char	*msg);

/* Free memory functions */
int		free_fdf(t_fdf *fdf);
void	free_arr(int **arr, int depth);
int		free_points(t_point *list);

/* Drawing image functions */
void	draw_map(t_fdf *fdf);
float	find_diff(int a, int b);
int		get_grad_color(int start, int end, double percentage);
double	find_percent(int start, int end, int current);
void	fill_background(t_fdf *fdf);
void	map_points(t_point *this, t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_point *start, t_point *end);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

/* Map rotation */
void	rotate_point(t_point *this, t_fdf *fdf);

/* t_point functions */
void	init_tpoint(t_point *this, int x, int y, int z);
t_point	*ft_point_new(char *z);
t_point	*ft_point_last(t_point *lst);
void	add_line_front(t_point **start, t_point *new);
void	ft_point_add_back(t_point **start, t_point *new);

void	draw_ui(t_fdf *fdf);
void	bonus_plus(t_fdf *fdf);
void	bonus_minus(t_fdf *fdf);

#endif
