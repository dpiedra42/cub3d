/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:22:42 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/07/07 18:15:23 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(int len, char *str)
{
	write(2, str, len);
	return (-1);
}

void	start_parse(t_all *all, char *cub)
{
	char	*ptr;
	int		fd;
	int		result;

	if ((fd = open(cub, O_RDONLY)) < 0)
		ft_error(32, "Error : couldnt open file (FD)\n");
	result = 1;
	while (result)
	{
		result = get_next_line(fd, &ptr);
		free(ptr);
	}
	close(fd);
}