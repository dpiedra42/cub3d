/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:18:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2021/01/09 01:14:57 by dpiedra          ###   ########.fr       */
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

void	wall_dist(t_all *all, int x)
{
	if (all->map->side == 0)
	{
		if (all->map->x < all->pos->x)
			all->ray->walldir = 'N';
		else
			all->ray->walldir = 'S';
		all->ray->wall_dist = (all->map->x - all->pos->x +
								(1 - all->map->step_x) / 2) / all->ray->x;
		all->ray->wallx = all->pos->y + all->ray->wall_dist * all->ray->y;
	}
	else
	{
		if (all->map->y < all->pos->y)
			all->ray->walldir = 'W';
		else
			all->ray->walldir = 'E';
		all->ray->wall_dist = (all->map->y - all->pos->y + (1 -
								all->map->step_y) / 2) / all->ray->y;
		all->ray->wallx = all->pos->x + all->ray->wall_dist * all->ray->x;
	}
	all->ray->zbuffer[x] = all->ray->wall_dist;
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
		wall_dist(all, x);
		line_height(all->ray, all->draw, all->pos);
		assign_text(all->text, all->ray);
		all->ray->wallx -= floor((all->ray->wallx));
		all->textx = all->ray->wallx * (all->text->text_sizel / 4);
		if (all->map->side == 0 && all->ray->x > 0)
			all->textx = (all->text->text_sizel / 4) - all->textx - 1;
		else if (all->map->side == 1 && all->ray->y < 0)
			all->textx = (all->text->text_sizel / 4) - all->textx - 1;
		draw_line(all, x);
		x++;
	}
}
