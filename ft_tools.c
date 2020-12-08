/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:59:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/12/08 15:35:35 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(int len, char *str)
{
	write(2, str, len);
	return (-1);
}

int	get_dist(t_all *all, int i)
{
	int distance;

	distance = ((all->pos->x - all->data->spr[i].x) *
				(all->pos->x - all->data->spr[i].x) +
	(all->pos->y - all->data->spr[i].y) * (all->pos->y - all->data->spr[i].y));
	return (distance);
}

int	numlen(const char *str)
{
	int i;

	i = 0;
	while (*str == ' ')
		str++;
	while ((*str >= '0' && *str <= '9'))
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_atoifc(const char *str)
{
	long int	num;

	num = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (numlen(str) > 3)
		return (-1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str++ - '0');
		else
			break ;
	}
	if (num < 0 || num > 255)
		return (-1);
	return ((int)num);
}

int	ft_atoi(const char *str)
{
	long int	num;

	num = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (numlen(str) > 4)
		return (42000);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str++ - '0');
		else
			break ;
	}
	return ((int)num);
}
