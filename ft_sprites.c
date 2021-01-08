/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:49:46 by deannapiedr       #+#    #+#             */
/*   Updated: 2021/01/07 04:14:55 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	order_sprites(t_all *all)
{
	double		spr_dist[all->sprnum];
	int			tmp;
	int			distmp;
	int			i;

	i = -1;
	while (++i < all->sprnum)
	{
		spr_dist[i] = get_dist(all, i);
		all->data->sprorder[i] = i;
	}
	i = -1;
	while (++i < all->sprnum - 1)
	{
		if (spr_dist[i] < spr_dist[i + 1])
		{
			distmp = spr_dist[i];
			spr_dist[i] = spr_dist[i + 1];
			spr_dist[i + 1] = distmp;
			tmp = all->data->sprorder[i];
			all->data->sprorder[i] = all->data->sprorder[i + 1];
			all->data->sprorder[i + 1] = tmp;
			i = -1;
		}
	}
}

void	sprite_height(t_all *all, t_sprite *sprite)
{
	sprite->spr_h = abs((int)(all->pos->height / sprite->trans_y));
	sprite->draws_y = -sprite->spr_h / 2 + all->pos->height / 2;
	if (sprite->draws_y < 0)
		sprite->draws_y = 0;
	sprite->drawe_y = sprite->spr_h / 2 + all->pos->height / 2;
	if (sprite->drawe_y >= all->pos->height)
		sprite->drawe_y = all->pos->height;
}

void	sprite_width(t_all *all, t_sprite *sprite)
{
	sprite->spr_w = abs((int)(all->pos->height / sprite->trans_y));
	sprite->draws_x = -sprite->spr_w / 2 + sprite->sprscreen_x;
	if (sprite->draws_x < 0)
		sprite->draws_x = 0;
	sprite->drawe_x = sprite->spr_w / 2 + sprite->sprscreen_x;
	if (sprite->drawe_x >= all->pos->width)
		sprite->drawe_x = all->pos->width;
}

void	draw_sprites(t_all *all, t_sprite *sprite, t_text *text)
{
	int y;
	int d;
	int stripe;

	stripe = sprite->draws_x;
	while (stripe < sprite->drawe_x)
	{
		all->textx = (int)((stripe - (-sprite->spr_w / 2 +
		sprite->sprscreen_x)) * text->textspr_width / sprite->spr_w);
		y = sprite->draws_y;
		if (sprite->trans_y > 0 && stripe >= 0 && stripe <
		all->pos->width && sprite->trans_y < (float)all->ray->zbuffer[stripe])
			while (y < sprite->drawe_y)
			{
				d = (y) * 256 - all->pos->height * 128 + sprite->spr_h * 128;
				sprite->ty = ((d * text->textspr_height) / sprite->spr_h) / 256;
				if (*(text->textspr_data + all->textx + sprite->ty *
					text->textspr_sizel / 4))
					*(all->data->i_data + stripe + y *
					all->data->sizel / 4) = *(text->textspr_data +
					all->textx + sprite->ty * text->textspr_sizel / 4);
				y++;
			}
		stripe++;
	}
}

void	make_sprite(t_all *all)
{
	int			i;
	t_spr		sprites;
	t_sprite	sprite;

	i = 0;
	order_sprites(all);
	while (i < all->sprnum)
	{
		sprites = all->data->spr[all->data->sprorder[i++]];
		sprite.spr_x = (sprites.x + 0.5) - all->pos->x;
		sprite.spr_y = (sprites.y + 0.5) - all->pos->y;
		sprite.invdet = 1.0 / (all->pos->plane_x * all->map->dir_y -
			all->map->dir_x * all->pos->plane_y);
		sprite.trans_x = sprite.invdet * (all->map->dir_y *
					sprite.spr_x - all->map->dir_x * sprite.spr_y);
		sprite.trans_y = sprite.invdet * ((-(all->pos->plane_y)) *
					sprite.spr_x + all->pos->plane_x * sprite.spr_y);
		sprite.sprscreen_x = (int)((all->pos->width / 2) *
					(1 + sprite.trans_x / sprite.trans_y));
		sprite_height(all, &sprite);
		sprite_width(all, &sprite);
		draw_sprites(all, &sprite, all->text);
	}
}
