/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:15:26 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 23:15:26 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* starting position of the ray*/

void	ft_set_rays_pos(t_cub *cub, int x)
{
	cub->rays.cam_x = 2 * x / (double)cub->map.x_size - 1;
	cub->rays.ray_d_x = cub->rays.d_x + \
	cub->rays.plane_x * cub->rays.cam_x;
	cub->rays.ray_d_y = cub->rays.d_y + \
	cub->rays.plane_y * cub->rays.cam_x;
	cub->rays.m_x = (int)cub->rays.p_x;
	cub->rays.m_y = (int)cub->rays.p_y;
}

/* calculate the delta dist using pythagorus theorom one side is always 1 unit
and when it is simplified it becomes dx = fabs(1 / dy) 
to find side_d_x and y if d_x is -ve m_x is subtracted and if it is +ve 
reverse it and add 1.0 to m_x */

void	ft_set_rays_dist(t_rays *rays)
{
	rays->delta_d_y = fabs(1 / rays->ray_d_x);
	rays->delta_d_x = fabs(1 / rays->ray_d_y);
	rays->hit = 0;
	if (rays->ray_d_x < 0)
	{
		rays->step_x = -1;
		rays->side_d_x = (rays->p_x - rays->m_x) * rays->delta_d_y;
	}
	else
	{
		rays->step_x = 1;
		rays->side_d_x = (rays->m_x + 1.0 - rays->p_x) * rays->delta_d_y;
	}
	if (rays->ray_d_y < 0)
	{
		rays->step_y = -1;
		rays->side_d_y = (rays->p_y - rays->m_y) * rays->delta_d_x;
	}
	else
	{
		rays->step_y = 1;
		rays->side_d_y = (rays->m_y + 1.0 - rays->p_y) * rays->delta_d_x;
	}
}

/* check if the wall is hit if not increment by delta*/

void	ft_check_hit(t_cub *cub)
{
	while (cub->rays.hit == 0)
	{
		if (cub->rays.side_d_x < cub->rays.side_d_y)
		{
			cub->rays.side_d_x += cub->rays.delta_d_y;
			cub->rays.m_x += cub->rays.step_x;
			cub->rays.side = 0;
		}
		else
		{
			cub->rays.side_d_y += cub->rays.delta_d_x;
			cub->rays.m_y += cub->rays.step_y;
			cub->rays.side = 1;
		}
		if (cub->map.map[cub->rays.m_x][cub->rays.m_y] == '1')
			cub->rays.hit = 1;
	}
}

/* use the the perpendicular distance from the camera plane to the wall
to avoid the fishey eye effect instead of using the eucilidean distance
from the player to the wall  and calculate the starting and end of wall
height*/

void	ft_set_project(t_rays *rays, t_map *map)
{
	if (rays->side == 0)
		rays->wall_dist = (rays->m_x - rays->p_x + \
		(1 - rays->step_x) / 2) / rays->ray_d_x;
	else
		rays->wall_dist = (rays->m_y - rays->p_y + \
		(1 - rays->step_y) / 2) / rays->ray_d_y;
	rays->l_height = (int)map->y_size / rays->wall_dist;
	rays->start_draw = -rays->l_height / 2 + map->y_size / 2;
	if (rays->start_draw < 0)
		rays->start_draw = 0;
	rays->end_draw = rays->l_height / 2 + map->y_size / 2;
	if (rays->end_draw >= map->y_size)
		rays->end_draw = map->y_size - 1;
}
