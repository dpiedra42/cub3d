/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:33:33 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/10/13 14:26:41 by deannapiedr      ###   ########.fr       */
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
			if (all->map->worldmap[x][y] == 2)
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
			if (map->worldmap[i][j] == 2)
				spr++;
			j++;
		}
		i++;
	}
	return (spr);
}

t_spr	*start_sprites(t_all *all)
{
	t_spr   *sprites;

	all->data->sprite->sprnum = count_sprites(all->map);
	all->data->sprite->sprorder = malloc(sizeof(int) * (all->data->sprite->sprnum));
	sprites = malloc(sizeof(t_spr) * all->data->sprite->sprnum);
	sprites = fill_spr(all, sprites);
	return (sprites);
}