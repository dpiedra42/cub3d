/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:18:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/08/26 20:23:47 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_raycast(t_pos *pos, t_map *map, t_ray *ray, int x)
{
	pos->camera_x = 2 * x / (double)pos->width - 1;
	ray->x = map->dir_x + pos->plane_x * pos->camera_x;
	ray->y = map->dir_y + pos->plane_y * pos->camera_x;
	map->x = (int)pos->x;
	map->y = (int)pos->y;
	ray->delta_x = fabs(1 / ray->x);
	ray->delta_y = fabs(1 / ray->y);
}

void	find_step(t_ray *ray, t_pos *pos, t_map *map)
{
	if (ray->x < 0)
	{
		map->step_x = -1;
		ray->side_x = (pos->x - map->x) * ray->delta_x;
	}
	else
	{
		map->step_x = 1;
		ray->side_x = (map->x + 1.0 - pos->x) * ray->delta_x;
	}
	if (ray->y < 0)
	{
		map->step_y = -1;
		ray->side_y = (pos->y - map->y) * ray->delta_y;
	}
	else
	{
		map->step_y = 1;
		ray->side_y = (map->y + 1.0 - pos->y) * ray->delta_y;
	}
}

void	wall_hit(t_ray *ray, t_map *map)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			map->x += map->step_x;
			map->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			map->y += map->step_y;
			map->side = 1;
		}
		if (map->worldmap[map->x][map->y] == 1) 
			hit = 1;
	}
}

void	wall_dist(t_map *map, t_ray *ray, t_pos *pos)
{
	if (map->side == 0)
	{
		if (map->x < pos->x)
			ray->walldir = 'N';
		else
			ray->walldir = 'S';
		ray->wall_dist = (map->x - pos->x + (1 - map->step_x) / 2) / ray->x;
		ray->wallx = pos->y + ray->wall_dist * ray->y;	
	}
	else
	{
		if (map->y < pos->y)
			ray->walldir = 'W';
		else
			ray->walldir = 'E';
		ray->wall_dist = (map->y - pos->y + (1 - map->step_y) / 2) / ray->y;
		ray->wallx = pos->x + ray->wall_dist * ray->x;
	}
	ray->wallx -= floor((ray->wallx));
}

void	raycast(t_all *all)
{
	int x;

	x = 0;
	while (x < all->pos->width)
	{
		start_raycast(all->pos, all->map, all->ray, x);
		find_step(all->ray, all->pos, all->map);
		wall_hit(all->ray, all->map);
		wall_dist(all->map, all->ray, all->pos);
		line_height(all->ray, all->draw, all->pos);
		assign_text(all->text, all->ray);
		all->textx = all->ray->wallx * (all->text->text_sizel / 4);
		if (all->map->side == 0 && all->ray->x > 0)
			all->textx = (all->text->text_sizel / 4) - all->textx - 1;
		else if (all->map->side == 1 && all->ray->y < 0)
			all->textx = (all->text->text_sizel / 4) - all->textx - 1;
		draw_line(all, x);
		x++;
	}
}