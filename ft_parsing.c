/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:22:42 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/07/10 19:05:06 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_parameters(char **gnl, t_all *all)
{
	
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

int	ft_error(int len, char *str)
{
	write(2, str, len);
	return (-1);
}

void	start_parse(t_all *all, char *cub)
{
	int	fd;
	
	if ((fd = open(cub, O_RDONLY)) < 0)
		ft_error(32, "Error : couldnt open file (FD)\n");
	all->map->gnl = 0;
	all->map->map = 0;
	all->map->gnl = copy_lines(all->map->gnl, fd);
	sort_parameters(all->map->gnl, all);
	close(fd);
}