/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:39:35 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/11/25 15:39:40 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_game(t_all *all)
{
	raycast(all);
	make_sprite(all);
	mlx_put_image_to_window(all->data->mlx_ptr, all->data->mlx_win,
							all->data->img, 0, 0);
	return (0);
}

int	start_window(t_all *all, int bmp, char **av)
{
	start_parse(all, av[1]);
	if ((all->data->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	txt_init(all->text, all->data);
	ft_rotate(-1, all->map, all->pos);
	ft_rotate(1, all->map, all->pos);
	ft_forback(-1, all->pos, all->map);
	ft_forback(1, all->pos, all->map);
	ft_leftright(1, all->pos, all->map);
	ft_leftright(-1, all->pos, all->map);
	all->data->img = mlx_new_image(all->data->mlx_ptr, all->pos->width,
										all->pos->height);
	all->data->i_data = (int *)mlx_get_data_addr(all->data->img,
			&(all->data->b), &(all->data->sizel), &(all->data->endi));
	if (bmp == 1)
		ft_makebitmap(all);
	if ((all->data->mlx_win = mlx_new_window(all->data->mlx_ptr,
		all->pos->width, all->pos->height, "raycaster")) == NULL)
		return (EXIT_FAILURE);
	mlx_hook(all->data->mlx_win, 2, 0, ft_keypress, (void *)all);
	mlx_hook(all->data->mlx_win, 17, 1, ft_close, (void *)all);
	mlx_loop_hook(all->data->mlx_ptr, print_game, (void *)all);
	mlx_loop(all->data->mlx_ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_pos		pos;
	t_map		map;
	t_data		data;
	t_ray		ray;
	t_draw		draw;
	t_all		all;
	t_text		text;

	//seven variable needs to be five

	all.text = &text;
	all.data = &data;
	all.pos = &pos;
	all.map = &map;
	all.ray = &ray;
	all.draw = &draw;
	if (ac == 3 && ft_checkcub(av[1], "cub") && ft_checksave(av[2], "--save"))
		start_window(&all, 1, av);
	else if (ac == 2 && ft_checkcub(av[1], "cub"))
		start_window(&all, 0, av);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}
