/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:49:33 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/26 15:21:22 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(int s, t_map *map, t_pos *pos)
{
	double oldDirX = map->dir_x;
	double oldPlaneX = pos->plane_x;
	double rspeed = 0.05;

	map->dir_x = map->dir_x * cos(s * rspeed) - map->dir_y * sin(s * rspeed);
	map->dir_y = oldDirX * sin(s * rspeed) + map->dir_y * cos(s * rspeed);
	pos->plane_x = pos->plane_x * cos(s * rspeed) - pos->plane_y * sin(s * rspeed);
	pos->plane_y = oldPlaneX * sin(s * rspeed) + pos->plane_y * cos(s * rspeed);
}

int		ft_keypress(int key, t_all *all)
{	
	// if (key == W)
	// 	ft_updown(key, all);
	// else if (key == A)
	// 	ft_leftright(key, all);
	// else if (key == S)
	// 	ft_updown(key,all);
	// else if (key == D)
	// 	ft_leftright(key, all);
	if (key == LEFT)
		ft_rotate(1, all->map, all->pos);
	else if (key == RIGHT)
		ft_rotate(-1, all->map, all->pos);
	// else if (key == ESC)
	// 	ft_close(key, all);
	return (1);
}