/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:19:08 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/12/08 15:34:14 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_error(char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ' ')
		str++;
	if (*str)
		ft_error(30, "Error : too many color inputs\n");
}

void	ft_ceiling(char *str, t_all *all)
{
	if (all->ceiling != 0)
		ft_error(32, "Error : Multiple ceiling inputs\n");
	all->ceiling = 1;
	while (*str == ' ')
		str++;
	all->draw->ceil_r = ft_atoifc(str);
	while ((*str >= '0' && *str <= '9') || *str == ' ')
		str++;
	if (*(str++) != ',')
		ft_error(38, "Error : Incorrect ceiling color input\n");
	all->draw->ceil_g = ft_atoifc(str);
	while ((*str >= '0' && *str <= '9') || *str == ' ')
		str++;
	if (*(str++) != ',')
		ft_error(38, "Error : Incorrect ceiling color input\n");
	all->draw->ceil_b = ft_atoifc(str);
	if (all->draw->ceil_r == -1 || all->draw->ceil_g == -1 ||
		all->draw->ceil_b == -1)
		ft_error(37, "Error : Wrong values for floor color\n");
	check_error(str);
}

void	ft_floor(char *str, t_all *all)
{
	if (all->floor != 0)
		ft_error(30, "Error : Multiple floor inputs\n");
	all->floor = 1;
	while (*str == ' ')
		str++;
	all->draw->floor_r = ft_atoifc(str);
	while ((*str >= '0' && *str <= '9') || *str == ' ')
		str++;
	if (*(str++) != ',')
		ft_error(36, "Error : Incorrect floor color input\n");
	all->draw->floor_g = ft_atoifc(str);
	while ((*str >= '0' && *str <= '9') || *str == ' ')
		str++;
	if (*(str++) != ',')
		ft_error(36, "Error : Incorrect floor color input\n");
	all->draw->floor_b = ft_atoifc(str);
	if (all->draw->floor_r == -1 || all->draw->floor_g == -1 ||
		all->draw->floor_b == -1)
		ft_error(37, "Error : Wrong values for floor color\n");
	check_error(str);
}

void	ft_res(char *str, t_all *all)
{
	if (all->res != 0)
		ft_error(35, "Error : Multiple resolution inputs\n");
	all->res = 1;
	while (*str == ' ')
		str++;
	all->pos->width = ft_atoi(&(*str));
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != ' ')
		ft_error(27, "Error : Wrong height input\n");
	while (*str == ' ')
		str++;
	all->pos->height = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ' ')
		str++;
	if (*str)
		ft_error(35, "Error : multiple resolution inputs\n");
	if (all->pos->width <= 0 || all->pos->height <= 0)
		ft_error(32, "Error : Wrong resolution values\n");
	if (all->pos->width > 2560)
		all->pos->width = 2560;
	if (all->pos->height > 1400)
		all->pos->height = 1400;
}
