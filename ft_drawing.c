/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:16:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/08/26 20:26:33 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_all *all, int x)
{
	int 	i;
	int		*text;
	double	step;
	double	textpos;

	i = -1;
	step = 1.0 * all->text->text_height / all->draw->line_height;
	textpos = (all->draw->start - all->pos->height / 2 + 
				all->draw->line_height / 2) * step;
	text = all->text->text_data;
	while (++i < all->draw->start)
		*(all->data->i_data + x + i * all->data->sizel / 4) = 0x96B2F2;
	while (i <= all->draw->end)
	{
		*(all->data->i_data + x + i++ * all->data->sizel / 4) = *(text + 
		all->textx + (int)textpos * all->text->text_sizel / 4);
		textpos += step;
	}
	while (i < all->pos->height)
		*(all->data->i_data + x + i++ * all->data->sizel / 4) = 0xCE97FE;
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
