/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:32:15 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/08/30 15:40:57 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fillmap(char **map, t_all *all)
{
	int	i;
	int	j;
	int	k;
	int	l;

	k = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		l = 0;
		while (map[i][j])
		{
			while (map[i][j] == ' ')
				j++;
			if (map[i][j])
				all->map->worldmap[k][l++] = map[i][j++] - '0';
		}
		j = 0;
		i++;
		k++;
	}
}

void	ft_startmap(t_all *all)
{
	int	i;
    int	j;
    
    i = 0;
	all->map->worldmap = malloc(sizeof(int *) * (all->map->max_y + 1));
	while (i <= all->map->max_y)
	{
		all->map->worldmap[i] = malloc(sizeof(int) * (all->map->max_x + 1));
		j = 0;
		while (j <= all->map->max_x)
		{
			all->map->worldmap[i][j] = -1;
			j++;
		}
		i++;
	}
}

int		ft_findx(char **map)
{
	int	i;
	int	j;
	int	len;
	int	ylen;

	i = 0;
	ylen = 0;
	while (map[i])
	{
		len = 0;
		j = 0;
		while (map[i][j])
		{
			if(map[i][j] != ' ')
				len++;
			j++;
		}
		if (len > ylen)
			ylen = len;
		i++;
	}
	return (ylen);
}

void	ft_map(char **map, t_all *all)
{
    int i;
	int j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (!map[i][j])
			tmp = 1;
		if (map[i][j] && tmp)
			ft_error(24, "Error : too many inputs\n");
		i++;
	}
	all->map->max_y = i;
    all->map->max_x = ft_findx(map);
    ft_startmap(all);
    ft_fillmap(map, all);
	ft_player(all);
}