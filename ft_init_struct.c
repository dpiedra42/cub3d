/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:49:37 by deannapiedr       #+#    #+#             */
/*   Updated: 2020/06/30 16:27:33 by deannapiedr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_struct(t_pos *pos, t_map *map)
{
    pos->x			=	10;
	pos->y			=	2;
    pos->plane_x	=	0;
	pos->plane_y	=	0.66;
    pos->width		=	640;
    pos->height		=	480;
    map->dir_x		=	1;
	map->dir_y		=	0;
}