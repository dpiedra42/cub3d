/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:39:35 by deannapiedr       #+#    #+#             */
/*   Updated: 2021/01/11 18:42:05 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		print_game(t_all *all)
{
	raycast(all);
	make_sprite(all);
	if (!all->screenshot)
		mlx_put_image_to_window(all->data->mlx_ptr, all->data->mlx_win,
							all->data->img, 0, 0);
	return (0);
}

int		start_window(t_all *all, int bmp, char **av)
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
		all->pos->width, all->pos->height, "Cub3d")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop_hook(all->data->mlx_ptr, print_game, all);
	mlx_hook(all->data->mlx_win, 2, 5, ft_keypress, all);
	mlx_hook(all->data->mlx_win, 33, 1, ft_close, all);
	mlx_loop(all->data->mlx_ptr);
	return (1);
}

void	start_param(t_all *all, int bmp, char **av)
{
	t_data		data;
	t_draw		draw;

	data.mlx_ptr = NULL;
	data.mlx_win = NULL;
	data.img = NULL;
	data.i_data = NULL;
	data.sizel = 0;
	data.b = 0;
	data.endi = 0;
	data.sprorder = NULL;
	data.spr = NULL;
	data.sprite = NULL;
	draw.line_height = 0;
	draw.start = 0;
	draw.end = 0;
	all->data = &data;
	all->draw = &draw;
	all->data->spr = NULL;
	all->data->sprite = NULL;
	start_window(all, bmp, av);
}

int		main(int ac, char **av)
{
	t_all		all;
	t_pos		pos;
	t_map		map;
	t_text		text;
	t_ray		ray;

	all.pos = &pos;
	all.map = &map;
	all.text = &text;
	all.ray = &ray;
	if (ac == 3 && ft_checkcub(av[1], "cub") && ft_checksave(av[2], "--save"))
		start_param(&all, 1, av);
	else if (ac == 2 && ft_checkcub(av[1], "cub"))
		start_param(&all, 0, av);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}
