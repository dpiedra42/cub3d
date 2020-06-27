/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:49:33 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/27 17:28:22 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_leftright(int s, t_pos *pos, t_map *map)
{
	double mspeed;

	mspeed = 0.5;
	if (s == -1)
	{
		if (worldmap[(int)(pos->x)][(int)(pos->y + map->dir_x * mspeed)] == 0)
			pos->y += map->dir_x * mspeed;
		if (worldmap[(int)(pos->x - map->dir_y * mspeed)][(int)(pos->y)] == 0)
			pos->x -= map->dir_y * mspeed;
	}
	if (s == 1)
	{
		if (worldmap[(int)(pos->x)][(int)(pos->y - map->dir_x * mspeed)] == 0)
			pos->y -= map->dir_x * mspeed;
		if (worldmap[(int)(pos->x + map->dir_y * mspeed)][(int)(pos->y)] == 0)
			pos->x += map->dir_y * mspeed;
	}
}

void	ft_forback(int s, t_pos *pos, t_map *map)
{
	double mspeed;

	mspeed = 0.5;
	if (s == -1)
    {
		if(worldmap[(int)(pos->x + map->dir_x * mspeed)][(int)pos->y] == 0)
			pos->x += map->dir_x * mspeed;
		if(worldmap[(int)(pos->x)][(int)(pos->y + map->dir_y * mspeed)] == 0)
			pos->y += map->dir_y * mspeed;
    }
    if (s == 1)
    {
		if(worldmap[(int)(pos->x - map->dir_x * mspeed)][(int)(pos->y)] == 0)
			pos->x -= map->dir_x * mspeed;
		if(worldmap[(int)(pos->x)][(int)(pos->y - map->dir_y * mspeed)] == 0)
			pos->y -= map->dir_y * mspeed;
	}
}

void	ft_rotate(int s, t_map *map, t_pos *pos)
{
	double oldDirX;
	double oldPlaneX;
	double rspeed;

	oldDirX = map->dir_x;
	oldPlaneX = pos->plane_x;
	rspeed = 0.05;
	map->dir_x = map->dir_x * cos(s * rspeed) - map->dir_y * sin(s * rspeed);
	map->dir_y = oldDirX * sin(s * rspeed) + map->dir_y * cos(s * rspeed);
	pos->plane_x = pos->plane_x * cos(s * rspeed) - pos->plane_y * sin(s * rspeed);
	pos->plane_y = oldPlaneX * sin(s * rspeed) + pos->plane_y * cos(s * rspeed);
}

int		ft_keypress(int key, t_all *all)
{	
	if (key == W)
		ft_forback(-1, all->pos, all->map);
	else if (key == S)
		ft_forback(1, all->pos, all->map);
	else if (key == A)
		ft_leftright(1, all->pos, all->map);
	else if (key == D)
		ft_leftright(-1, all->pos, all->map);
	else if (key == LEFT)
		ft_rotate(-1, all->map, all->pos);
	else if (key == RIGHT)
		ft_rotate(1, all->map, all->pos);
	return (1);
}
	// else if (key == ESC)
	// 	ft_close(key, all);