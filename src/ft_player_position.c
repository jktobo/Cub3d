/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:37:18 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/14 22:37:18 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* find the player position and replace it with 0 so it can be passable*/

int	ft_player_position(t_map *map)
{
	int		x;
	int		y;

	map->map_height = ft_array_length(map->map);
	y = 0;
	while (y < map->map_height)
	{
		x = ft_strmatch(map->map[y], "NSEW");
		if (x >= 0)
			break ;
		y++;
	}
	if (x >= 0)
	{
		map->x_move = x;
		map->y_move = y;
		map->player_dir = map->map[y][x];
		map->map[map->y_move][map->x_move] = '0';
		return (0);
	}
	return (error_msg("Error saving player position"));
}

/*find the player positions if not return error and also
check if there is multiple positions*/

int	ft_check_player_pos(t_map *map)
{
	int		i;

	i = ft_strmatch(map->map_start, "NSEW");
	if (i == -1)
		return (1);
	i = ft_strmatch(map->map_start + i + 1, "NSEW");
	if (i != -1)
		return (1);
	return (0);
}
