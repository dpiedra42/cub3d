/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:49:37 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/18 16:34:59 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_pos(t_pos *pos, t_map *map)
{
    pos->x			=	2;
	pos->y			=	3;
    pos->plane_x	=	0;
	pos->plane_y	=	0.66;
    pos->width		=	450;
    pos->height		=	400;
    map->dir_x		=	-1;
	map->dir_y		=	0;
}