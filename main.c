/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 17:08:28 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/07/10 18:49:57 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int print_game(t_all *all)
{
	raycast(all->pos, all->map, all->ray, all->data, all->draw, all->text);
	mlx_put_image_to_window(all->data->mlx_ptr, all->data->mlx_win,
							all->data->img.ptr, 0, 0);
	return (0);
}

int	start_window(t_all *all, int ac, char **av)
{
	start_struct(all->pos, all->map);
	if ((all->data->mlx_ptr = mlx_init()) == NULL)
    	return (EXIT_FAILURE);
	start_parse(all, av[1]);
	start_texture(all->text, all->data);
    if ((all->data->mlx_win = mlx_new_window(all->data->mlx_ptr, all->pos->width,
		all->pos->height, "raycaster")) == NULL)
    	return (EXIT_FAILURE);
	all->data->img.ptr = mlx_new_image(all->data->mlx_ptr, all->pos->width,
										all->pos->height);
	all->data->img.data = (int *)mlx_get_data_addr(all->data->img.ptr, 
			&(all->data->img.b), &(all->data->img.sizel), &(all->data->img.endi));
	mlx_hook(all->data->mlx_win, 2, 0, ft_keypress, all);
	mlx_loop_hook(all->data->mlx_ptr, print_game, all);
	mlx_loop(all->data->mlx_ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_pos	pos;
	t_map	map;
	t_data	data;
	t_ray	ray;
	t_draw	draw;
	t_all	all;
	t_text  text;

	all.text	=	&text;
	all.data	=	&data;
	all.pos		=	&pos;
	all.map		=	&map;
	all.ray		=	&ray;
	all.draw	=	&draw;
	start_window(&all, ac, av);
	return (0);
}

// gcc mlxline.c -o mlxline.a -Lminilibx_og  -lmlx -framework OpenGL -framework AppKit