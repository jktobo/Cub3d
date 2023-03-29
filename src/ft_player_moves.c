/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:16:54 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 06:13:54 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* check the map if the player postion is 0 and increment*/

int	player_moves(t_cub *cub, double x, double y)
{
	if (cub->map.map[(int)(cub->rays.p_x \
	+ x * cub->rays.step_size)] \
		[(int)(cub->rays.p_y)] == '0')
	{
		ft_put_image(cub);
		ft_load_image(cub);
		cub->rays.p_x += x * (cub->rays.step_size - 0.01);
	}
	if (cub->map.map[(int)(cub->rays.p_x)] \
		[(int)(cub->rays.p_y + y * cub->rays.step_size)] == '0')
	{
		ft_put_image(cub);
		ft_load_image(cub);
		cub->rays.p_y += y * (cub->rays.step_size - 0.01);
	}
	return (0);
}

/* players rotation used the matrix rotation formula to find the 
x and y coordinates*/

int	ft_player_rot(t_cub *cub, double rad)
{
	double		old_d_x;
	double		old_p_x;

	old_d_x = cub->rays.d_x;
	cub->rays.d_x = cub->rays.d_x * cos(rad) - cub->rays.d_y * sin(rad);
	cub->rays.d_y = old_d_x * sin(rad) + cub->rays.d_y * cos(rad);
	old_p_x = cub->rays.plane_x;
	cub->rays.plane_x = cub->rays.plane_x * \
	cos(rad) - cub->rays.plane_y * sin(rad);
	cub->rays.plane_y = old_p_x * sin(rad) + \
	cub->rays.plane_y * cos(rad);
	ft_put_image(cub);
	ft_load_image(cub);
	return (0);
}
