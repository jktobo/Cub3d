/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:32:29 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/15 02:32:29 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* read the map and trim all the variables from the map and if there 
	is error it will free all and exit */

int	ft_init_cub(t_cub *cub, char *map_name)
{
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (error_msg("Unable to open map file"));
	if (ft_read_map(&(cub->map.long_str), fd) == -1)
		return (error_msg("Error reading cub map"));
	if (ft_trim_resolution(cub->map.long_str, &cub->map.x_size, 0) \
		|| ft_trim_resolution(cub->map.long_str, &cub->map.y_size, 1) \
		|| ft_trim_dir_tex(&cub->map) \
		|| ft_trim_color(cub->map.long_str, &(cub->map.c_color), "C " ) \
		|| ft_trim_color(cub->map.long_str, &(cub->map.f_color), "F " ) \
		|| ft_trim_map(&cub->map, cub->map.long_str) \
		|| ft_player_position(&cub->map))
	{
		ft_free_all(&(cub->map), 1);
		return (1);
	}
	close(fd);
	return (0);
}
