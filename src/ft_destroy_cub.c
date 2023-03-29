/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:22:22 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/28 04:50:44 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* free all variables and destroys the given window at exit*/

int	ft_destroy_cub(t_cub *cub)
{
	ft_freedouble(cub->map.map);
	mlx_destroy_window(cub->game.mlx, cub->game.mlx_win);
	exit (0);
	return (1);
}
