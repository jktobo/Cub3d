/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:18:14 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/29 00:53:34 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* initialize the rays variable with the default values p_x (0.5) b/c it 
start at the middle of (the ratio between the length of direction and
camera plane determines FOV the map plane_y (0.66) screen aspect ratio
cos_rad PI / 0 rotation speed */

static	void	player_orient2(t_cub *cub)
{
	if (cub->map.player_dir == 'E')
	{
		cub->rays.d_x = 1.0;
		cub->rays.d_y = 0.0;
		cub->rays.plane_x = 0.0;
		cub->rays.plane_y = 0.66;
	}
	else if (cub->map.player_dir == 'W')
	{
		cub->rays.d_x = -1.0;
		cub->rays.d_y = 0.0;
		cub->rays.plane_x = 0.0;
		cub->rays.plane_y = -0.66;
	}
}

static	void	player_orient(t_cub *cub)
{
	if (cub->map.player_dir == 'N')
	{
		cub->rays.d_x = 0.0;
		cub->rays.d_y = -1.0;
		cub->rays.plane_x = 0.66;
		cub->rays.plane_y = 0.0;
	}
	else if (cub->map.player_dir == 'S')
	{
		cub->rays.d_x = 0.0;
		cub->rays.d_y = 1.0;
		cub->rays.plane_x = -0.66;
		cub->rays.plane_y = 0.0;
	}
	else
		player_orient2(cub);
}

int	ft_ray_init(t_cub *cub)
{
	cub->rays.p_x = cub->map.y_move + 0.5;
	cub->rays.p_y = cub->map.x_move + 0.5;
	cub->rays.step_size = 0.1;
	cub->rays.const_rad = M_PI / 60;
	cub->rays.forward = 0;
	cub->rays.backword = 0;
	cub->rays.left = 0;
	cub->rays.right = 0;
	cub->rays.rot_left = 0;
	cub->rays.rot_right = 0;
	player_orient(cub);
	return (0);
}
