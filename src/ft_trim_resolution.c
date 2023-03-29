/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:55:44 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/29 23:55:48 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*gets the screen resolution from the map by reading the R */

int	ft_trim_resolution(char *long_str, int *w_size, int index)
{
	char	*line;
	char	**res;

	line = NULL;
	line = ft_trim_line(long_str, "R ");
	if (!line)
	{
		free(line);
		return (error_msg("Resolution not found"));
	}
	res = ft_split(line, ' ');
	free(line);
	if (!res[1])
	{
		ft_freedouble(res);
		return (error_msg("Incomplete render size"));
	}
	*w_size = ft_atoi(res[index]);
	ft_freedouble(res);
	if (*w_size < 1)
		return (error_msg("Invalid resolution"));
	return (0);
}

/*check if the screen resolution is greater than the computer
 default resolution if it is it will adjust it the fit inside the
 resolution by multiplying the default resolution by 0.5*/

int	ft_valid_res_size(t_cub *cub)
{
	int	x;
	int	y;

	mlx_get_screen_size(&(cub->game.mlx), &x, &y);
	if (x < cub->map.x_size || y < cub->map.y_size)
	{
		printf("Resolution size is too big\n");
		cub->map.x_size = x * 0.5;
		cub->map.y_size = y * 0.5;
	}
	return (0);
}
