/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:18:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/15 16:05:18 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_raycast(t_pos pos, t_map map, t_ray ray, int x)
{
	pos.camera_x = 2 * x / (double)pos.width - 1;
    ray.x = map.dir_x + pos.plane_x * pos.camera_x;
    ray.y = map.dir_y + pos.plane_y * pos.camera_x;
	map.x = (int)pos.x;
    map.y = (int)pos.y;
	ray.delta_x = fabs(1 / ray.x);
	ray.delta_y = fabs(1 / ray.y);
}

void	find_step(t_ray ray, t_pos pos, t_map map)
{
	 if (ray.x < 0)
      {
        map.step_x = -1;
        ray.side_x = (pos.x - map.x) * ray.delta_x;
      }
      else
      {
        map.step_x = 1;
        ray.side_x = (map.x + 1.0 - pos.x) * ray.delta_x;
      }
      if (ray.y < 0)
      {
        map.step_y = -1;
        ray.side_y = (pos.y - map.y) * ray.delta_y;
      }
      else
      {
        map.step_y = 1;
        ray.side_y = (map.y + 1.0 - pos.y) * ray.delta_y;
      }
}

void	wall_hit(t_ray ray, t_pos pos, t_map map)
{
	int hit;

	hit = 0;
	while (hit == 0)
    {
    	if (ray.side_x < ray.side_y)
    	{
        	ray.side_x += ray.delta_x;
        	map.x += map.step_x;
        	map.side = 0;
   		}
    	else
    	{
        	ray.side_y += ray.delta_y;
        	map.y += map.step_y;
        	map.side = 1;
    	}
    	if (worldmap[map.x][map.y] > 0) 
			hit = 1;
    }
}

void	wall_dist(t_map map, t_ray ray, t_pos pos)
{
      if (map.side == 0) 
	  	ray.wall_dist = (map.x - pos.x + (1 - map.step_x) / 2) / ray.x;
      else           
	  	ray.wall_dist = (map.y - pos.y + (1 - map.step_y) / 2) / ray.y;
}

void    raycast(t_pos pos, t_map map, t_ray ray, t_data data, t_draw draw)
{
    int x;

    x = 0;
    while (x < pos.width)
	{
		start_raycast(pos, map, ray, x);
		find_step(ray, pos, map);
		hit_wall(ray, pos, map);
		wall_dist(map, ray, pos);
        line_height(ray, draw);
        wall_color(draw, map);
        draw_ine(draw, data, pos, x);
		x++;
	}
}