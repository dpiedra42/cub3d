/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:19:08 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/08/24 20:13:44 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_res(char *str, t_all *all)
{
	if (all->res != 0)
		ft_error(35, "Error : Multiple resolution inputs\n");
	all->res = 1;
	all->pos->width = ft_atoi(&(*str));
	while ((*str >= '0' && *str <= '9'))
		str++;
	if (*str != ' ')
		ft_error(27, "Error : Wrong height input\n");
	all->pos->height = ft_atoi(str);
	while ((*str >= '0' && *str <= '9'))
		str++;
	while (*str == ' ')
		str++;
	if (*str)
		ft_error(35, "Error : multiple resolution inputs\n");
	if (all->pos->width <= 0 || all->pos->height <= 0)
		ft_error(31, "Error : too many height inputs\n");
	if (all->pos->width > 2560)
		all->pos->width = 2560;
	if (all->pos->height > 1400)
		all->pos->height = 1400;
}