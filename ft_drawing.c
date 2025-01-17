/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:16:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2021/01/07 22:03:59 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		conv_color(int red, int green, int blue)
{
	int rgb;

	rgb = red * 256 * 256 + green * 256 + blue;
	return (rgb);
}

void	draw_line(t_all *all, int x)
{
	int		i;
	int		*text;
	double	step;
	double	textpos;

	i = -1;
	step = 1.0 * all->text->text_height / all->draw->line_height;
	textpos = (all->draw->start - all->pos->height / 2 +
				all->draw->line_height / 2) * step;
	text = all->text->text_data;
	while (++i <= all->draw->start)
		*(all->data->i_data + x + i * all->data->sizel / 4) =
		conv_color(all->draw->ceil_r, all->draw->ceil_g, all->draw->ceil_b);
	while (i <= all->draw->end)
	{
		*(all->data->i_data + x + i++ * all->data->sizel / 4) = *(text +
		all->textx + (int)textpos * all->text->text_sizel / 4);
		textpos += step;
	}
	while (i < all->pos->height)
		*(all->data->i_data + x + i++ * all->data->sizel / 4) =
		conv_color(all->draw->floor_r, all->draw->floor_g, all->draw->floor_b);
}

void	line_height(t_ray *ray, t_draw *draw, t_pos *pos)
{
	draw->line_height = (int)(pos->height / ray->wall_dist);
	draw->start = (draw->line_height * -1) / 2 + pos->height / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->line_height / 2 + pos->height / 2;
	if (draw->end >= pos->height)
		draw->end = pos->height - 1;
}
