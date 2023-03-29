/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:31:30 by yoyohann          #+#    #+#             */
/*   Updated: 2023/03/15 02:31:30 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* get red color from  int color*/

int	get_r(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}

/* get green color from int color*/

int	get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

/* get blue color from int color*/

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}

/* return a color int from individual r g b colors*/

int	ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/* create a darker version of the color
 by subtructing dark value*/

int	ft_dark_color(int color, int dark)
{
	int		r;
	int		g;
	int		b;

	r = get_r(color) - dark;
	if (r < 0)
		r = 0;
	g = get_g(color) - dark;
	if (g < 0)
		g = 0;
	b = get_b(color) - dark;
	if (b < 0)
		b = 0;
	color = ft_create_rgb(r, g, b);
	return (color);
}
