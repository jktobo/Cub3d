/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:14:22 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 23:14:22 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* event handler when key is pressed and change the values
 to 1 based on the pressed key*/

int	ft_key_pressed(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		ft_destroy_cub(cub);
	if (keycode == FORWARD)
		cub->rays.forward = 1;
	else if (keycode == BACKWARD)
		cub->rays.backword = 1;
	else if (keycode == LEFT)
		cub->rays.left = 1;
	else if (keycode == RIGHT)
		cub->rays.right = 1;
	else if (keycode == LROTATE)
		cub->rays.rot_left = 1;
	else if (keycode == RROTATE)
		cub->rays.rot_right = 1;
	return (keycode);
}

/* assign the value to 0 when the key is released*/

int	ft_key_released(int keycode, t_cub *cub)
{
	if (keycode == FORWARD)
		cub->rays.forward = 0;
	else if (keycode == BACKWARD)
		cub->rays.backword = 0;
	else if (keycode == LEFT)
		cub->rays.left = 0;
	else if (keycode == RIGHT)
		cub->rays.right = 0;
	else if (keycode == LROTATE)
		cub->rays.rot_left = 0;
	else if (keycode == RROTATE)
		cub->rays.rot_right = 0;
	return (keycode);
}
