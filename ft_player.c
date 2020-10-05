/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:35:13 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/09/29 12:41:55 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	we_point(char spawn, t_all *all)
{
	if (spawn == 'W')
	{
		all->map->dir_x = 0;
		all->map->dir_y = -1;
		all->pos->plane_x = -0.66;
		all->pos->plane_y = 0;
	}
	else if (spawn == 'E')
	{
		all->map->dir_x = 0;
		all->map->dir_y = 1;
		all->pos->plane_x = 0.66;
		all->pos->plane_y = 0;
	}
}

void	ns_point(char spawn, t_all *all)
{
	if (spawn == 'N')
	{
		all->map->dir_x = -1;
		all->map->dir_y = 0;
		all->pos->plane_x = 0;
		all->pos->plane_y = 0.66;
	}
	else if (spawn == 'S')
	{
		all->map->dir_x = 1;
		all->map->dir_y = 0;
		all->pos->plane_x = 0;
		all->pos->plane_y = -0.66;
	}
}

int		start_player(int x, int y, char spawn, t_all *all)
{
	if (spawn != 'N' && spawn != 'S' && spawn != 'E' && spawn != 'W')
		ft_error(26, "Error : Wrong spawn point\n");
	if (all->pos->playerpos > 0)
		ft_error(26,"Error : Many spawn points\n");
	all->pos->x = x + 0.5;
	all->pos->y = y + 0.5;
	if (spawn == 'N' || spawn == 'S')
		ns_point(spawn, all);
	else
		we_point(spawn, all);
	return (1);
}

int		map_val(int val, int x, int y, t_all *all)
{
	if (val != 1 && val != 2 && val != 0 && val != -1)
	{
		start_player(x, y, (val + 48), all);
		return (1);
	}
	return (0);
}

void	ft_player(t_all *all)
{
	int i;
	int j;

	i = 0;
	all->pos->playerpos = 0;
	while (i <= all->map->max_y)
	{
		j = 0;
		while (j <= all->map->max_x)
		{
			all->pos->playerpos += map_val(all->map->worldmap[i][j], i, j , all);
			j++;
		}
		i++;
	}
	if (all->pos->playerpos == 0)
		ft_error(31, "Error : No defined start point\n");
}