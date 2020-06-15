/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:16:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/15 16:09:53 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_line(t_draw draw, t_data data, t_pos pos, int x)
{
    int i;

    i = -1;
    while (++i < draw.draw_start)
	{
		*(data.img.data + x + i * data.img.sizel / 4) = draw.color;
	}
	while (i < pos.height)
		*(data.img.data + x + i++ * data.img.sizel / 4) = draw.color;
}

void    wall_color(t_draw draw, t_map map)
{
    if (worldmap[map.x][map.y] >= 0)
        draw.color = 0xFABCFA;
    if (map.side == 1) 
        draw.color = draw.color / 2;
}

void    line_height(t_ray ray, t_draw draw)
{
    draw.line_height = draw.h / (int)ray.wall_dist;
    draw.draw_start = (draw.line_height * -1) / 2 + draw.h / 2;
    if (draw.draw_start < 0)
        draw.draw_start = 0;
    draw.draw_end = draw.line_height / 2 + draw.h / 2;
    if (draw.draw_end >= draw.h)
        draw.draw_end = draw.h - 1;
}
