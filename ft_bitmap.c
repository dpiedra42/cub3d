/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:04:13 by deannapiedr       #+#    #+#             */
/*   Updated: 2021/01/08 17:46:11 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_data(t_all *all, int fd)
{
	unsigned char	buffer[4];
	int				i;
	int				j;

	i = all->pos->width * (all->pos->height - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < all->pos->width)
		{
			buffer[0] = (unsigned char)(all->data->i_data[i] % 256);
			buffer[1] = (unsigned char)(all->data->i_data[i] / 256 % 256);
			buffer[2] = (unsigned char)(all->data->i_data[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			j++;
			i++;

		}
		i -= 2 * all->pos->width;
	}
}

void	bmp_info(t_all *all, int fd)
{
	int	headersize;
	int	plane;
	int	image_size;

	headersize = 40;
	plane = 1;
	image_size = all->pos->width * all->pos->height;
	write(fd, &headersize, 4);
	write(fd, &all->pos->width, 4);
	write(fd, &all->pos->height, 4);
	write(fd, &plane, 2);
	write(fd, &all->data->b, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	bmp_header(t_all *all, int fd)
{
	int filesize;
	int offbit;

//fix
	offbit = 54;
	filesize = offbit + (all->pos->width * all->pos->height) * 4;     
	write(fd, "BM", 2);
	write(fd, &filesize, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offbit, 4);
}

void	ft_makebitmap(t_all *all)
{
	int fd;

	all->screenshot = 1;
	print_game(all);
	if ((fd = open("bitmap.bmp", O_WRONLY | O_CREAT | 0664 | O_APPEND | O_TRUNC)) < 0)
		ft_error(25, "Error: Can't make bitmap\n");
	bmp_header(all, fd);
	bmp_info(all, fd);
	bmp_data(all, fd);
	close(fd);
	ft_close(all);
}
