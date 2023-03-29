/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:55:34 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/29 23:55:34 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*check if the first and last row of the map is coved with wall*/

static int	valid_row(char **map, int y)
{
	int		x;
	int		len;

	x = 0;
	len = ft_strlen(map[y]);
	while (x < len)
	{
		if (ft_chrmatch(map[y][x], "02NSEW"))
			return (1);
		x++;
	}
	return (0);
}

/* check if the first and last colomn of the map is covered
 with wall*/

static int	valid_col(char **map, int x)
{
	int		y;
	int		len;

	y = 0;
	while (y < x)
	{
		len = ft_strlen(map[y]);
		if (ft_chrmatch(map[y][0], "02NSEW") \
			|| ft_chrmatch(map[y][len - 1], "02NSEW"))
			return (1);
		y++;
	}
	return (0);
}

/* check if c is empty space or new line*/

static int	valid_chr(char c)
{
	if (!c)
		return (1);
	if (c == ' ' || c == '\n')
		return (1);
	else
		return (0);
}

/* check the all side of the the inside map and see if
all the 8 neigbours are not new line or empty space */

static int	valid_adj(char **map, int x, int y)
{
	if (ft_chrmatch(map[y][x], "02NSEW") \
		&& (valid_chr(map[y - 1][x]) \
		|| valid_chr(map[y + 1][x]) \
		|| valid_chr(map[y][x - 1]) \
		|| valid_chr(map[y][x + 1]) \
		|| valid_chr(map[y - 1][x - 1]) \
		|| valid_chr(map[y + 1][x + 1]) \
		|| valid_chr(map[y - 1][x + 1]) \
		|| valid_chr(map[y + 1][x - 1])))
		return (1);
	else
		return (0);
}

/* check if the map has a valid characters*/

int	ft_valid_map(t_map *map)
{
	int		x;
	int		y;
	int		len;

	if (valid_row(map->map, 0) \
	|| valid_row(map->map, map->map_height - 1) \
	|| valid_col(map->map, map->map_height))
		return (1);
	y = 1;
	while (y < map->map_height - 1)
	{
		x = 1;
		len = ft_strlen(map->map[y]);
		while (x < len - 1)
		{
			if (valid_adj(map->map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
