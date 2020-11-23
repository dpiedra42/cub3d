/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:04:13 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/11/23 18:31:08 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_data(t_all *all, int fd)
{
	unsigned char	buffer[4];
	int				i;
	int				j;

	i = all->pos->width * (all->pos->height - 1);
	while(i >= 0)
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
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = all->pos->width;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = all->pos->height;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);

}

void	bmp_header(t_all *all, int fd)
{
	unsigned char	header[14];
	int				n;

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = all->pos->height * all->pos->width * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	ft_makebitmap(t_all *all)
{
	int fd;

	print_game(all);
	if ((fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) < 0)
		ft_error(25, "Error: Can't make bitmap\n");
	bmp_header(all, fd);
	bmp_info(all, fd);
	bmp_data(all, fd);
	close(fd);
	ft_close(all);
}