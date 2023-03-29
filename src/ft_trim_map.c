/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:55:54 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/29 23:55:57 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* search for the begining of the map index by locating the two consecutive 
 new lines */

static int	begin_index(char *long_str)
{
	int		i;
	int		flag;

	i = ft_strlen(long_str) - 1;
	flag = 1;
	while (long_str[i] && i > 0)
	{
		if (!ft_chrmatch(long_str[i], "102NSEW \n"))
			flag = 0;
		i--;
		if (long_str[i] == '\n' && long_str[i - 1] == '\n' && flag == 1)
			return (i - 1);
	}
	return (-1);
}

/* create the map starting from the start index to the end of file
 and assing every line to the map at the same time get the height of 
 the map*/

int	ft_trim_map(t_map *map, char *long_str)
{
	int		first_index;
	int		i;
	int		width;

	first_index = begin_index(long_str);
	if (first_index == -1)
		return (error_msg("Invalid map"));
	map->map_start = long_str + first_index;
	map->map = ft_split(map->map_start, '\n');
	while (map->map[map->map_height])
		map->map_height++;
	i = 0;
	width = ft_strlen(map->map[i]);
	while (i < map->map_height)
	{
		if (ft_strlen(map->map[i]) > width)
			width = ft_strlen(map->map[i]);
		i++;
	}
	map->map_width = width;
	if (ft_check_player_pos(map))
		return (error_msg("player position not found"));
	if (ft_valid_map(map))
		return (error_msg("Wall is not closed"));
	return (0);
}
