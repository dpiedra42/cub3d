/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:27:58 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/11/21 17:47:21 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_checkcub(char *av, char *str)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if ((i > 4 && av[i - 1] == str[2] && av[i - 2] == str[1])
		&& (av[i - 3] == str[0] && av[i - 4] == '.'))
		return (1);
	return (0);
}

int	ft_checksave(char *av, char *str)
{
	return (0);
}