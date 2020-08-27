/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:59:30 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/08/27 17:30:39 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(int len, char *str)
{
	write(2, str, len);
	return (-1);
}

static int	numlen(const char *str)
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

int		ft_atoi(const char *str)
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
			break;
	}
	return ((int)num);
}