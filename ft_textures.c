/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:55:42 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/12/08 15:35:16 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_checkcont(t_all *all, int c)
{
	if (c == 4)
	{
		if (all->txt4)
			ft_error(27, "Error: E texture set twice\n");
		else
			all->txt4 = 1;
	}
	if (c == 5)
	{
		if (all->sprtxt)
			ft_error(29, "Error: SPR texture set twice\n");
		else
			all->sprtxt = 1;
	}
}

void	texture_check(int c, t_all *all)
{
	if (c == 1)
	{
		if (all->txt1)
			ft_error(27, "Error: N texture set twice\n");
		else
			all->txt1 = 1;
	}
	if (c == 2)
	{
		if (all->txt2)
			ft_error(28, "Error: SO texture set twice\n");
		else
			all->txt2 = 1;
	}
	if (c == 3)
	{
		if (all->txt3)
			ft_error(27, "Error: W texture set twice\n");
		else
			all->txt3 = 1;
	}
	if (c == 4 || c == 5)
		texture_checkcont(all, c);
}

void	start_texture(t_all *all, char *str, int c)
{
	int fd;

	while (*str == ' ')
		str++;
	if ((fd = open(str, O_RDONLY)) < 0)
		ft_error(27, "Error : wrong texture path\n");
	close(fd);
	if (c == 1)
		all->text->txt1_p = str;
	if (c == 2)
		all->text->txt2_p = str;
	if (c == 3)
		all->text->txt3_p = str;
	if (c == 4)
		all->text->txt4_p = str;
	if (c == 5)
		all->text->txtspr_p = str;
	texture_check(c, all);
}

void	assign_text(t_text *text, t_ray *ray)
{
	if (ray->walldir == 'N')
	{
		text->text_data = text->text1_data;
		text->text_sizel = text->text1_sizel;
		text->text_height = text->text1_height;
	}
	else if (ray->walldir == 'S')
	{
		text->text_data = text->text2_data;
		text->text_sizel = text->text2_sizel;
		text->text_height = text->text2_height;
	}
	else if (ray->walldir == 'W')
	{
		text->text_data = text->text3_data;
		text->text_sizel = text->text3_sizel;
		text->text_height = text->text3_height;
	}
	else
	{
		text->text_data = text->text4_data;
		text->text_sizel = text->text4_sizel;
		text->text_height = text->text4_height;
	}
}

void	txt_init(t_text *text, t_data *data)
{
	text->text1 = mlx_xpm_file_to_image(data->mlx_ptr,
	text->txt1_p, &(text->text1_width), &(text->text1_height));
	text->text2 = mlx_xpm_file_to_image(data->mlx_ptr,
	text->txt2_p, &(text->text2_width), &(text->text2_height));
	text->text3 = mlx_xpm_file_to_image(data->mlx_ptr,
	text->txt3_p, &(text->text3_width), &(text->text3_height));
	text->text4 = mlx_xpm_file_to_image(data->mlx_ptr,
	text->txt4_p, &(text->text4_width), &(text->text4_height));
	text->textspr = mlx_xpm_file_to_image(data->mlx_ptr,
	text->txtspr_p, &(text->textspr_width), &(text->textspr_height));
	text->text1_data = (int *)mlx_get_data_addr(text->text1,
	&text->text1_b, &text->text1_sizel, &text->text1_endi);
	text->text2_data = (int *)mlx_get_data_addr(text->text2,
	&text->text2_b, &text->text2_sizel, &text->text2_endi);
	text->text3_data = (int *)mlx_get_data_addr(text->text3,
	&text->text3_b, &text->text3_sizel, &text->text3_endi);
	text->text4_data = (int *)mlx_get_data_addr(text->text4,
	&text->text4_b, &text->text4_sizel, &text->text4_endi);
	text->textspr_data = (int *)mlx_get_data_addr(text->textspr,
	&text->textspr_b, &text->textspr_sizel, &text->textspr_endi);
}
