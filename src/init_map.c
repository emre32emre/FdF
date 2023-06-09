/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:32:37 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/14 03:35:09 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error_messages.h"

static void	free_and_exit(char *str, t_point *current_line, t_point *start)
{
	free(str);
	free_points(current_line);
	free_points(start);
	exit_on_error(ERR_MEM);
}

int	parse_line(char **str, t_point **start)
{
	char	**nums;
	t_point	*tmp;
	t_point	*current_line;
	int		i;

	i = 0;
	tmp = NULL;
	current_line = NULL;
	nums = ft_split(*str, ' ');
	while (nums && nums[i])
	{
		tmp = ft_point_new(nums[i]);
		if (!tmp)
			break ;
		ft_point_add_back(&current_line, tmp);
		i++;
	}
	ft_split_free(nums);
	if (!tmp)
		free_and_exit(*str, current_line, *start);
	add_line_front(start, current_line);
	free(*str);
	*str = NULL;
	return (i);
}

t_point	*read_map(int fd, t_map *map_i)
{
	int		res;
	t_point	*flat_map;
	char	*line;
	int		width;

	width = 0;
	flat_map = NULL;
	line = NULL;
	res = get_next_line(fd, &line);
	while (res != 0 && ++map_i->map_h)
	{
		if (res == -1 && free_points(flat_map))
			exit_on_error(ERR_MEM);
		width = parse_line(&line, &flat_map);
		if (map_i->map_h == 1)
			map_i->map_w = width;
		if (map_i->map_h != 1 && width != map_i->map_w && free_points(flat_map))
			return (NULL);
		res = get_next_line(fd, &line);
	}
	free(line);
	return (flat_map);
}

static int	colors_empty(int **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map[i][j] != COL_VIOLET)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init_map(char *map_file, t_fdf *fdf)
{
	int		fd;
	t_point	*flat_map;

	flat_map = NULL;
	if (open(map_file, O_DIRECTORY) != -1)
		exit_on_error(ERR_FD_IS_DIR);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit_on_error(ERR_FD_OPEN);
	flat_map = read_map(fd, &fdf->map_i);
	if (close(fd) == -1)
		exit_on_error(ERR_FD_CLOSE);
	if (!flat_map)
		exit_on_error(ERR_LINE_W);
	list_to_arr(flat_map, fdf);
	free_points(flat_map);
	if (colors_empty(fdf->map_i.color, fdf->map_i.map_w, fdf->map_i.map_h))
		update_colors(fdf);
}
