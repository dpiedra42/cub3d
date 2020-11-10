/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:58:54 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/11/01 16:44:46 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
# include "./minilibx_og/mlx.h"

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct    s_data
{
    void          *mlx_ptr;
    void          *mlx_win;
    t_img         img;
}                 t_data;

int main(void)
{
    t_data  data;
    int     count_w;
    int     count_h;
    int     i;

    count_h = -1;
    i = 0;
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 400, 450, "sup")) == NULL)
        return (EXIT_FAILURE);
    data.img.ptr = mlx_new_image(data.mlx_ptr, 400, 450);
    data.img.data = (int *)mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.size_l,
		&data.img.endian);
    while (++count_h < 450)
	{
		count_w = -1;
		while (++count_w < 400)
        {  
			if (count_w == i)
				data.img.data[count_h * 400 + count_w] = 0xFABCFA;
			else
				data.img.data[count_h * 400 + count_w] = 0xFCFBFC;
		}
        i++;
	}
    mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.ptr, 0, 0);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
// gcc test.c -o test.a -Lminilibx_og  -lmlx -framework OpenGL -framework AppKit
