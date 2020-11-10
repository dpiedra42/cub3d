/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:49:33 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/11/07 17:13:09 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_all *all)
{
	int i;

	i = 0;
	if (all->map->gnl)
	{
		while (all->map->gnl[i])
		{
			free(all->map->gnl[i]);
			i++;
		}
		free(all->map->gnl);
	}
	exit(EXIT_SUCCESS);
}

void	ft_leftright(int b, t_pos *pos, t_map *map)
{
	double mspeed;

	mspeed = 0.5;
	if (b == -1)
	{
		if (map->worldmap[(int)(pos->x)][(int)(pos->y + map->dir_x * mspeed)] != 1)
			pos->y += map->dir_x * mspeed * 0.5;
		if (map->worldmap[(int)(pos->x - map->dir_y * mspeed)][(int)(pos->y)] != 1)
			pos->x -= map->dir_y * mspeed * 0.5;
	}
	if (b == 1)
	{
		if (map->worldmap[(int)(pos->x)][(int)(pos->y - map->dir_x * mspeed)] != 1)
			pos->y -= map->dir_x * mspeed * 0.5;
		if (map->worldmap[(int)(pos->x + map->dir_y * mspeed)][(int)(pos->y)] != 1)
			pos->x += map->dir_y * mspeed * 0.5;
	}
}

void	ft_forback(int b, t_pos *pos, t_map *map)
{
	double mspeed;

	mspeed = 0.5;
	if (b == -1)
    {
		if(map->worldmap[(int)(pos->x + map->dir_x * mspeed)][(int)pos->y] != 1)
			pos->x += map->dir_x * mspeed * 0.5;
		if(map->worldmap[(int)(pos->x)][(int)(pos->y + map->dir_y * mspeed)] != 1)
			pos->y += map->dir_y * mspeed * 0.5;
    }
    if (b == 1)
    {
		if(map->worldmap[(int)(pos->x - map->dir_x * mspeed)][(int)(pos->y)] != 1)
			pos->x -= map->dir_x * mspeed * 0.5;
		if(map->worldmap[(int)(pos->x)][(int)(pos->y - map->dir_y * mspeed)] != 1)
			pos->y -= map->dir_y * mspeed * 0.5;
	}
}

void	ft_rotate(int b, t_map *map, t_pos *pos)
{
	double oldDirX;
	double oldPlaneX;
	double rspeed;

	oldDirX = map->dir_x;
	oldPlaneX = pos->plane_x;
	rspeed = 0.05;
	map->dir_x = map->dir_x * cos(b * rspeed) - map->dir_y * sin(b * rspeed);
	map->dir_y = oldDirX * sin(b * rspeed) + map->dir_y * cos(b * rspeed);
	pos->plane_x = pos->plane_x * cos(b * rspeed) - pos->plane_y * sin(b * rspeed);
	pos->plane_y = oldPlaneX * sin(b * rspeed) + pos->plane_y * cos(b * rspeed);
}

int		ft_keypress(int key, t_all *all)
{	
	if (key == W)
		ft_forback(-1, all->pos, all->map);
	else if (key == S)
		ft_forback(1, all->pos, all->map);
	else if (key == A)
		ft_leftright(-1, all->pos, all->map);
	else if (key == D)
		ft_leftright(1, all->pos, all->map);
	else if (key == LEFT)
		ft_rotate(1, all->map, all->pos);
	else if (key == RIGHT)
		ft_rotate(-1, all->map, all->pos);
	else if (key == ESC)
		ft_close(all);
	return (1);
}
