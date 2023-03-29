/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:57:06 by dkaratae          #+#    #+#             */
/*   Updated: 2023/03/29 23:57:09 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* check if the color values are only number and convet it to numbers*/

static int	ft_valid_rgb(t_rgb *rgb, char **colors)
{
	int		i;
	int		ret;

	if (!colors || !colors[2])
		return (error_msg("Invalid or Incomplete colors"));
	i = 0;
	while (colors[i])
	{
		ret = is_digit(colors[i]);
		if (ret == 0)
			return (error_msg("Invalid rgb value"));
		i++;
	}
	rgb->r = ft_atoi(colors[0]);
	rgb->g = ft_atoi(colors[1]);
	rgb->b = ft_atoi(colors[2]);
	if (rgb->r > 255 || rgb->g > 255 || rgb->b > 255 \
	|| rgb->r < 0 || rgb->g < 0 || rgb->b < 0)
		return (error_msg("Out of range rgb value"));
	return (0);
}

/* read the color values and convert the individual colors to
single unsigned int color*/

int	ft_trim_color(char *long_str, unsigned int *c_color, char *c)
{
	char	*line;
	char	**color;
	t_rgb	rgb;

	ft_memset(&rgb, 0, sizeof(t_rgb));
	line = ft_trim_line(long_str, c);
	if (!line)
		return (error_msg("Color not found"));
	color = ft_split(line, ',');
	if (ft_valid_rgb(&rgb, color))
	{
		ft_freedouble(color);
		free(line);
		return (1);
	}
	ft_freedouble(color);
	free(line);
	*c_color = ft_create_rgb(rgb.r, rgb.g, rgb.b);
	return (0);
}
