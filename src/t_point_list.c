/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:32:46 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/14 03:32:54 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_tpoint(t_point *this, int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

t_point	*ft_point_new(char *z)
{
	t_point	*point;
	char	**str;

	str = NULL;
	if (ft_strchr(z, ','))
	{
		str = ft_split(z, ',');
		if (!str)
			return (NULL);
	}
	point = (t_point *)malloc(sizeof(t_point));
	if (point)
	{
		if (str)
			point->z = ft_atoi(str[0]);
		else
			point->z = ft_atoi(z);
		if (str)
			point->color = ft_atoi_base(str[1], 16);
		else
			point->color = COL_VIOLET;
		point->next = NULL;
	}
	ft_split_free(str);
	return (point);
}

void	add_line_front(t_point **start, t_point *new)
{
	t_point	*tmp;

	tmp = ft_point_last(new);
	if (new)
	{
		tmp->next = *start;
		*start = new;
	}
}

t_point	*ft_point_last(t_point *lst)
{
	t_point	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_point_add_back(t_point **start, t_point *new)
{
	t_point	*tmp;

	if (start)
	{
		if (*start && new)
		{
			tmp = ft_point_last(*start);
			tmp->next = new;
		}
		else
			*start = new;
	}
}
