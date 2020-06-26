/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:16:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/26 15:45:19 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_draw *draw, t_data *data, t_pos *pos, int x)
{
	int i;

	i = -1;
	while (++i < draw->start)
		*(data->img.data + x + i * data->img.sizel / 4) = 0x96B2F2;
	while (i <= draw->end)
		*(data->img.data + x + i++ * data->img.sizel / 4) = draw->color;
	while (i < pos->height)
		*(data->img.data + x + i++ * data->img.sizel / 4) = 0xCE97FE;
}

void	wall_color(t_draw *draw, t_map *map)
{
	if (worldmap[map->x][map->y] >= 0)
		draw->color = 0xF296C1; //pink/purple
	if (map->side == 1) 
		draw->color = draw->color / 2;
}

void	line_height(t_ray *ray, t_draw *draw, t_pos *pos)
{
	draw->line_height = pos->height / (int)ray->wall_dist;
	draw->start = (draw->line_height * -1) / 2 + pos->height / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->line_height / 2 + pos->height / 2;
	if (draw->end >= pos->height)
		draw->end = pos->height - 1;
}
