/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:49:46 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/09/28 19:32:46 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_width(t_all *all, t_sprite *sprite)
{
	sprite->spr_w = abs((int)(all->pos->height / sprite->trans_y));
	sprite->draws_x = -sprite->spr_w / 2 + sprite->sprscreen_x;
	if (sprite->draws_x < 0)
		sprite->draws_x = 0;
	sprite->drawe_x = sprite->spr_w / 2 + sprite->sprscreen_x;
	if(sprite->drawe_x >= all->pos->width)
		sprite->drawe_x = all->pos->width - 1;
}

void	sprite_height(t_all *all, t_sprite *sprite)
{
	sprite->spr_h == fabs((int)(all->pos->height / sprite->trans_y));
	sprite->draws_y = -sprite->spr_h / 2 + all->pos->height / 2;
	if (sprite->draws_y < 0)
		sprite->draws_y = 0;
	sprite->drawe_y = sprite->spr_h / 2 + all->pos->height / 2;
	if (sprite->drawe_y >= all->pos->height)
		sprite->drawe_y = all->pos->height - 1;
}

void	start_sprite(t_all *all, t_sprite *sprite)
{
	int i;

	i = 0;	
	sprite->spr_x = sprite->x - all->pos->x;
	sprite->spr_y = sprite->y - all->pos->y;
	sprite->invdet = 1.0 / (all->pos->plane_x * all->map->dir_y -
			all->map->dir_x * all->pos->plane_y);
	sprite->trans_x = sprite->invdet * (all->map->dir_y *
					sprite->spr_x - all->map->dir_x * sprite->spr_y);
	sprite->trans_y = sprite->invdet * ((-(all->pos->plane_y)) *
					sprite->spr_x + all->pos->plane_x * sprite->spr_y);
	sprite->sprscreen_x = (int)((all->pos->width / 2) *
					(1 + sprite->trans_x / sprite->trans_y));
}