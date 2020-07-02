/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:16:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/07/02 16:12:15 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw_line(t_text *text, t_draw *draw, t_data *data, t_pos *pos, int x)
{
	int i;
	double	step;
	double	textpos;

	i = -1;
	step = 1.0 * text->pink_height / draw->line_height;
	textpos = (draw->start - pos->height / 2 + draw->line_height / 2) * step;
	while (++i < draw->start)
		*(data->img.data + x + i * data->img.sizel / 4) = 0x96B2F2;
	while (i <= draw->end)
	{
		*(data->img.data + x + i++ * data->img.sizel / 4) = *(text->pink_data
		+ text->textx + (int)textpos * text->pink_sizel / 4);
		textpos += step;
	}
	while (i < pos->height)
		*(data->img.data + x + i++ * data->img.sizel / 4) = 0xCE97FE;
	return (1);
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
