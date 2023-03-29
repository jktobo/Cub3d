/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:15:05 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 23:15:05 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* calculate and check everything and put the image on the screen*/

int	ft_put_image(t_cub *cub)
{
	int		x;

	draw_backbg(cub);
	x = 0;
	while (x < cub->map.x_size)
	{
		ft_set_rays_pos(cub, x);
		ft_set_rays_dist(&(cub->rays));
		ft_check_hit(cub);
		ft_set_project(&(cub->rays), &(cub->map));
		if (cub->rays.side == 0 && cub->rays.step_x == 1)
			put_texture(cub, cub->tex.no_img, x);
		if (cub->rays.side == 0 && cub->rays.step_x == -1)
			put_texture(cub, cub->tex.so_img, x);
		if (cub->rays.side == 1 && cub->rays.step_y == 1)
			put_texture(cub, cub->tex.ea_img, x);
		if (cub->rays.side == 1 && cub->rays.step_y == -1)
			put_texture(cub, cub->tex.we_img, x);
		x++;
	}
	return (0);
}
