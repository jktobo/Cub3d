/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:21:29 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/28 03:48:19 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* all possible moves forward and backward right left and rotate right and left
the diffence is forward is positive and backward become negative
right is positive and left is negative , left_rot angle is negative and
right_rot is negative*/

int	ft_valid_moves(t_cub *cub)
{
	if (cub->rays.forward)
		player_moves(cub, cub->rays.d_x, cub->rays.d_y);
	if (cub->rays.backword)
		player_moves(cub, -cub->rays.d_x, -cub->rays.d_y);
	if (cub->rays.left)
		player_moves(cub, -cub->rays.plane_x, \
		-cub->rays.plane_y);
	if (cub->rays.right)
		player_moves(cub, cub->rays.plane_x, \
		cub->rays.plane_y);
	if (cub->rays.rot_left)
		ft_player_rot(cub, cub->rays.const_rad);
	if (cub->rays.rot_right)
		ft_player_rot(cub, -cub->rays.const_rad);
	return (1);
}
