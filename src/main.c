/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 05:17:07 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/14 05:17:07 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* check for error and initialize all variables 
	handle keyboard and mouse events*/
int	main(int argc, char **argv)
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(t_cub));
	if (ft_check_error(argc, argv))
		return (1);
	if (ft_init_cub(&(cub), argv[1])
		|| ft_init_texture(&cub) \
		|| ft_ray_init(&cub) \
		|| ft_init_mlx(&cub) \
		|| ft_put_image(&cub) \
		|| ft_load_image(&cub))
		return (1);
	mlx_loop_hook(cub.game.mlx, &ft_valid_moves, &cub);
	mlx_hook(cub.game.mlx_win, DESTROY, 0, &ft_destroy_cub, &cub);
	mlx_hook(cub.game.mlx_win, PRESS, 0, &ft_key_pressed, &cub);
	mlx_hook(cub.game.mlx_win, RELEASE, 0, &ft_key_released, &cub);
	mlx_loop(cub.game.mlx);
	return (0);
}
