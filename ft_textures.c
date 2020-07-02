/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:55:42 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/07/02 15:12:59 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    start_texture(t_text *text, t_data *data)
{
	text->pink = mlx_xpm_file_to_image(data->mlx_ptr,
	pinkpath, &(text->pink_width), &(text->pink_height));
	text->pink_data = (int *)mlx_get_data_addr(text->pink,
	&text->pink_b, &text->pink_sizel, &text->pink_endi);
}