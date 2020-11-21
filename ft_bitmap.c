/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:04:13 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/11/21 19:05:14 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_header(t_all *all, int fd)
{
	unsigned char	header[54];
	int i;
	int size;

	i = 0;
	while (i < 54)
		header[i++] = (unsigned char)(0);
	size = all->pos->height * all->pos->width * 4;
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size + 54);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(all->pos->width);
	header[22] = (unsigned char)(all->pos->height);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	header[34] = (unsigned char)(size);
	write(fd, header, 54);
}

void	ft_makebitmap(t_all *all)
{
	int fd;

	print_game(all);
	if ((fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) < 0)
		ft_error(27, "Error: E can't make bitmap\n");
	bmp_header(all, fd);
	// bmp_data
	close(fd);
	ft_close(all);
}