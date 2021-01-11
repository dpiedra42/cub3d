/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:33:33 by deannapiedr       #+#    #+#             */
/*   Updated: 2021/01/11 17:24:51 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_spr	*fill_spr(t_all *all, t_spr *sprites)
{
	int i;
	int x;
	int y;

	x = 0;
	i = 0;
	while (x < all->map->max_y)
	{
		y = 0;
		while (y < all->map->max_x)
		{
			if (all->map->worldmap[x][y] == 4)
			{
				sprites[i].x = x;
				sprites[i++].y = y;
			}
			y++;
		}
		x++;
	}
	return (sprites);
}

int		count_sprites(t_map *map)
{
	int i;
	int j;
	int spr;

	i = 0;
	spr = 0;
	while (i < map->max_y)
	{
		j = 0;
		while (j < map->max_x)
		{
			if (map->worldmap[i][j] == 4)
				spr++;
			j++;
		}
		i++;
	}
	return (spr);
}

t_spr	*start_sprites(t_all *all)
{
	t_spr	*sprites;

	all->sprnum = 0;
	all->sprnum = count_sprites(all->map);
	sprites = malloc(sizeof(t_spr) * all->sprnum);
	all->data->sprorder = malloc(sizeof(int) * (all->sprnum));
	sprites = fill_spr(all, sprites);
	return (sprites);
}
