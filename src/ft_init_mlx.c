/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:19:10 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/15 02:08:33 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* Initialize the connection b/n the software and the display,
 manage the window, manipulate the image and 
 mlx_get_data_addr returns the char* address that represent the begining 
 of the memory area the image is stored*/

int	ft_init_mlx(t_cub *cub)
{
	cub->game.mlx = mlx_init();
	if (ft_valid_res_size(cub))
		return (error_msg("Resolution size is too big\n"));
	cub->game.mlx_win = mlx_new_window(cub->game.mlx, \
	cub->map.x_size, cub->map.y_size, "Cub3D");
	cub->game.img = mlx_new_image(cub->game.mlx, \
	cub->map.x_size, cub->map.y_size);
	cub->game.addr = mlx_get_data_addr(cub->game.img, \
	&(cub->game.bit_per_pixel), &(cub->game.line_length), &(cub->game.endian));
	cub->game.width = cub->map.x_size;
	cub->game.height = cub->map.y_size;
	return (0);
}

/* user can draw and dump an image inside a specified window to display
it on the screen*/

int	ft_load_image(t_cub *cub)
{
	mlx_put_image_to_window(&(cub->game.mlx), \
	cub->game.mlx_win, cub->game.img, 0, 0);
	return (0);
}
