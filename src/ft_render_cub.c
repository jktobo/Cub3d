/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:01:27 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 07:14:45 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/* line_length address to of the line
bit_per_pixel represent color of the first pixel
get the color for the pixel*/

static void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->game.addr + (y * cub->game.line_length \
	+ x * (cub->game.bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* draw color*/

static void	horizontal_fill(t_cub *cub, int i, int color)
{
	int		j;

	j = 0;
	while (j < cub->map.x_size)
	{
		put_pixel(cub, j, i, color);
		j++;
	}
}

/* draw background color base on the color*/

int	draw_backbg(t_cub *cub)
{
	int		i;
	int		color;

	i = 0;
	color = cub->map.c_color;
	while (i < cub->map.y_size / 2)
	{
		if (cub->map.y_size / 200 == 0 || i % (cub->map.y_size) == 0)
			color = ft_dark_color(color, 1);
		horizontal_fill(cub, i, color);
		i++;
	}
	while (i < cub->map.y_size)
	{
		horizontal_fill(cub, i, cub->map.f_color);
		i++;
	}
	return (0);
}

/* calculate the texture coordinates*/

int	set_texture(t_cub *cub, t_game game)
{
	if (cub->rays.side == 0)
		cub->rays.w_x = cub->rays.p_y + \
		cub->rays.wall_dist * cub->rays.ray_d_y;
	else
		cub->rays.w_x = cub->rays.p_x + \
		cub->rays.wall_dist * cub->rays.ray_d_x;
	cub->rays.w_x -= floor(cub->rays.w_x);
	cub->rays.t_x = (int)(cub->rays.w_x * (double )game.width);
	if ((cub->rays.side == 0 && cub->rays.ray_d_x > 0) \
		|| (cub->rays.side == 1 && cub->rays.ray_d_y < 0))
	cub->rays.t_x = game.width - cub->rays.t_x;
	cub->rays.t_y = 0;
	cub->rays.t_y_step = game.height / (double)cub->rays.l_height;
	if (cub->rays.l_height > cub->map.y_size)
		cub->rays.t_y = (cub->rays.l_height - \
		cub->map.y_size) * cub->rays.t_y_step / 2;
	return (0);
}

/* put the texture on the pixel*/

int	put_texture(t_cub *cub, t_game game, int x)
{
	char	*dst;
	int		wall_y;
	int		color;

	set_texture(cub, game);
	wall_y = cub->rays.start_draw;
	while (wall_y < cub->rays.end_draw)
	{
		dst = game.addr + ((int)(cub->rays.t_y) % game.height * \
			game.line_length + cub->rays.t_x % game.width \
			* (game.bit_per_pixel / 8));
		color = *(unsigned int *)dst;
		put_pixel(cub, x, wall_y, color);
		wall_y++;
		cub->rays.t_y += cub->rays.t_y_step;
	}
	return (0);
}
