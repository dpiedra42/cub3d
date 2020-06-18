/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 17:08:28 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/18 16:50:54 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_window(t_all *all)
{
	start_struct(all->pos, all->map);
	if ((all->data->mlx_ptr = mlx_init()) == NULL)
    	return (EXIT_FAILURE);
    if ((all->data->mlx_win = mlx_new_window(all->data->mlx_ptr, all->pos->width,
		all->pos->height, "raycaster")) == NULL)
    	return (EXIT_FAILURE);
	all->data->img.ptr = mlx_new_image(all->data->mlx_ptr, all->pos->width,
										all->pos->height);
	all->data->img.data = (int *)mlx_get_data_addr(all->data->img.ptr, 
			&(all->data->img.b), &(all->data->img.sizel), &(all->data->img.endi));
	mlx_put_image_to_window(all->data->mlx_ptr, all->data->mlx_win,
							all->data->img.ptr, 0, 0);
	raycast(all->pos, all->map, all->ray, all->data, all->draw);
	mlx_loop(all->data->mlx_ptr);
	return (1);
}

int	main(void)
{
	t_pos	pos;
	t_map	map;
	t_data	data;
	t_ray	ray;
	t_draw	draw;
	t_all	all;

	all.data	=	&data;
	all.pos		=	&pos;
	all.map		=	&map;
	all.ray		=	&ray;
	all.draw	=	&draw;
	start_window(&all);
	return (0);
}

// gcc mlxline.c -o mlxline.a -Lminilibx_og  -lmlx -framework OpenGL -framework AppKit