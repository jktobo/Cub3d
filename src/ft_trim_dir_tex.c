/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_dir_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:30:03 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/29 23:56:58 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* read the file map and assign the texture files */

int	ft_trim_dir_tex(t_map *map)
{
	map->no = ft_trim_line(map->long_str, "NO ");
	map->so = ft_trim_line(map->long_str, "SO ");
	map->ea = ft_trim_line(map->long_str, "EA ");
	map->we = ft_trim_line(map->long_str, "WE ");
	if (!map->so || !map->no || !map->ea || !map->we)
	{
		free(map->no);
		free(map->so);
		free(map->ea);
		free(map->we);
		free(map->long_str);
		return (error_msg("Direction path not found"));
	}
	return (0);
}
