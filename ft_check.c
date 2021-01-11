/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:27:58 by deannapiedr       #+#    #+#             */
/*   Updated: 2021/01/11 17:38:53 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_checkcub(char *av, char *str)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (i > 4 && av[i - 1] == str[2] && av[i - 2] == str[1]
		&& (av[i - 3] == str[0] && av[i - 4] == '.'))
		return (1);
	return (0);
}

int		ft_checksave(char *av, char *str)
{
	int	i;

	i = 0;
	while (av[i] == str[i])
	{
		if (av[i] == '\0' && str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_checkmap(t_all *all, int i, int j)
{
	int **map;

	map = all->map->worldmap;
	if (map[i][j] == 1 || map[i][j] == 3 || map[i][j] == 4)
		return ;
	if (i == 0 || j == 0 || i == all->map->max_y)
		ft_error(all, 28, "Map not closed around spawn\n");
	if (map[i][j] == -1)
		ft_error(all, 28, "Map not closed around spawn\n");
	if (map[i][j] == 0)
		map[i][j] = 3;
	if (map[i][j] == 2)
		map[i][j] = 4;
	ft_checkmap(all, i + 1, j);
	ft_checkmap(all, i, j + 1);
	ft_checkmap(all, i - 1, j);
	ft_checkmap(all, i, j - 1);
}
