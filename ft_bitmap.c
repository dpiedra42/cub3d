/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:04:13 by deannapiedr       #+#    #+#             */
/*   Updated: 2021/01/11 16:45:07 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_data(t_all *all, int fd)
{
	int i;
	int j;
	int pixel;

	i = all->pos->height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < all->pos->width)
		{
			pixel = *(all->data->i_data + j + i * all->data->sizel / 4);
			write(fd, &pixel, 4);
			j++;
		}
		i--;
	}
}

void	bmp_info(t_all *all, int fd)
{
	int	headersize;
	int	plane;
	int i;
	int k;

	headersize = 40;
	plane = 1;
	k = all->pos->width;
	write(fd, &headersize, 4);
	write(fd, &k, 4);
	write(fd, &all->pos->height, 4);
	write(fd, &plane, 2);
	write(fd, &all->data->b, 2);
	i = 0;
	while (i < 28)
	{
		write(fd, "\0", 1);
		i++;
	}
}

void	bmp_header(t_all *all, int fd)
{
	int filesize;
	int offbit;

	offbit = 58;
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
	if ((fd = open("bitmap.bmp", O_WRONLY | O_CREAT, 0777
		| O_APPEND | O_TRUNC)) < 0)
		ft_error(all, 25, "Error: Can't make bitmap\n");
	bmp_header(all, fd);
	bmp_info(all, fd);
	bmp_data(all, fd);
	close(fd);
	ft_close(all);
}
