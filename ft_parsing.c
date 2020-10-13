/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:22:42 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/10/13 15:15:07 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_line(char c, char *str, t_all *all)
{
	while (*str == ' ')
		str++;
	if (c == 'R' && *(str + 1) == ' ')
		ft_res(str + 1, all);
	else if (c == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		start_texture(all, str + 2, 1);
	else if (c == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		start_texture(all, str + 2, 2);
	else if (c == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		start_texture(all, str + 2, 3);
	else if (c == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		start_texture(all, str + 2, 4);
	else if (c == 'S' && *(str + 1) == ' ')
		start_texture(all, str + 1, 5);
	else if (c == 'F' && *(str + 1) == ' ')
		ft_floor(str + 1, all);
	else if (c == 'C' && *(str + 1) == ' ')
		ft_ceiling(str + 1, all);
	else if (c == '0' || c == '1' || c == '2')
		return (0);
	else if (c)
		ft_error(29, "Error : Invalid line in file\n");
	return (1);
}

char	**sort_parameters(char **gnl, t_all *all)
{
	int i;
	int	j;

	i = 0;
	while (gnl[i])
	{
		j = 0;
		while(gnl[i][j] == ' ')
			j++;
		if(!ft_line(gnl[i][j], gnl[i], all))
		{
			return (&gnl[i]);
		}
		i++;
	}
	ft_error(21, "Error : no map found\n");
	return(gnl);
}

char	**copy_lines(char **gnl, int fd)
{
	char	*ptr;
	char	**tmp;
	int		i;
	int		j;
	int		result;

	i = 1;
	result = 1;
	while (result)
	{
		j = 0;
		result = get_next_line(fd, &ptr);
		tmp = gnl;
		gnl = malloc(sizeof(char *) * (i + 1));
		if (tmp)
		{
			while (tmp[j])
			{
				gnl[j] = tmp[j];
				j++;
			}
		}
		free(tmp);
		gnl[j++] = ptr;
		gnl[j] = 0;
		i++;
	}
	return (gnl);
}

void	init_params(t_all *all)
{
	all->res = 0;
	all->txt1 = 0;
	all->txt2 = 0;
	all->txt3 = 0;
	all->txt4 = 0;
	all->sprtxt = 0;
	all->floor = 0;
	all->ceiling = 0;
}

void	start_parse(t_all *all, char *cub)
{
	int	fd;
	
	if ((fd = open(cub, O_RDONLY)) < 0)
		ft_error(32, "Error : couldnt open file (FD)\n");
	all->map->gnl = 0;
	all->map->map = 0;
	all->map->gnl = copy_lines(all->map->gnl, fd);
	close(fd);
	init_params(all);
	all->map->map = sort_parameters(all->map->gnl, all);
	ft_map(all->map->map, all);
	all->data->spr = start_sprites(all);
}