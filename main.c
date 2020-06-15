/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 17:08:28 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/15 17:13:15 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(void)
{
	t_pos	pos;
	t_map	map;
	t_data  data;
	t_ray	ray;
	t_draw	draw;

	pos = start_pos(pos);
	map = start_map(map);
	
	if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, pos.width, pos.height,
	"raycaster")) == NULL)
        return (EXIT_FAILURE);
	data.img.ptr = mlx_new_image(data.mlx_ptr, pos.width, pos.height);
    data.img.data = (int *)mlx_get_data_addr(data.img.ptr, &data.img.b, &data.img.sizel,
		&data.img.endi);
	raycast(pos, map, ray, data, draw);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}

// gcc mlxline.c -o mlxline.a -Lminilibx_og  -lmlx -framework OpenGL -framework AppKit