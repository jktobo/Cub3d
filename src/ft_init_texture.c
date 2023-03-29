/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:17:28 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/28 03:37:48 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* create an image and fill it using the specified name and xpm data*/

static int	create_img(t_game *game, char *file_name)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (error_msg("mlx creation failed"));
	game->img = mlx_xpm_file_to_image(game->mlx, \
	file_name, &(game->width), &(game->height));
	if (!(game->img))
	{
		mlx_destroy_image(game->mlx, game->img);
		printf("Error!\n %s not found\n", file_name);
		return (1);
	}
	game->addr = mlx_get_data_addr(game->img, \
	&(game->bit_per_pixel), &(game->line_length), \
	&(game->endian));
	if (game->addr == NULL)
		mlx_destroy_image(game->mlx, game->img);
	return (0);
}

/* read the map and create the texutres */

int	ft_init_texture(t_cub *cub)
{
	if (create_img(&(cub->tex.no_img), cub->map.no) \
		|| create_img(&(cub->tex.so_img), cub->map.so) \
		|| create_img(&(cub->tex.ea_img), cub->map.ea) \
		|| create_img(&(cub->tex.we_img), cub->map.we))
		return (ft_free_all(&(cub->map), 0));
	free(cub->map.no);
	free(cub->map.so);
	free(cub->map.ea);
	free(cub->map.we);
	return (0);
}
