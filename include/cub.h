/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:22:33 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 06:52:05 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define BUFFER_SIZE 512
# define LROTATE 123
# define RROTATE 124
# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define PRESS 2
# define RELEASE 3
# define DESTROY 17

typedef struct t_game
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_game;

typedef struct s_rays
{
	double		p_x;
	double		p_y;
	double		d_x;
	double		d_y;
	double		plane_x;
	double		plane_y;
	double		step_size;
	double		const_rad;
	int			forward;
	int			backword;
	int			left;
	int			right;
	int			rot_left;
	int			rot_right;
	int			side;
	double		w_x;
	int			w_y;
	double		ray_d_x;
	double		ray_d_y;
	int			t_x;
	double		t_y;
	double		t_y_step;
	int			l_height;
	int			start_draw;
	int			end_draw;
	int			s_x;
	int			s_y;
	double		cam_x;
	int			m_x;
	int			m_y;
	double		delta_d_x;
	double		delta_d_y;
	int			hit;
	int			step_x;
	int			step_y;
	double		side_d_x;
	double		side_d_y;
	double		wall_dist;
}	t_rays;

typedef struct s_map
{
	char			*long_str;
	int				x_size;
	int				y_size;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	unsigned int	c_color;
	unsigned int	f_color;
	char			*map_start;
	char			**map;
	int				map_width;
	int				map_height;
	int				x_move;
	int				y_move;
	char			player_dir;
	int				x_p;
	int				y_p;
}	t_map;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	int		color;
}	t_rgb;

typedef struct s_tex
{
	t_game	no_img;
	t_game	so_img;
	t_game	ea_img;
	t_game	we_img;
}	t_tex;

typedef struct s_cub
{
	t_game	game;
	t_rays	rays;
	t_map	map;
	t_rgb	rgb;
	t_tex	tex;
}	t_cub;

int			main(int argc, char **argv);
int			ft_valid_map(t_map *map);
int			error_msg(char *msg);
int			ft_check_player_pos(t_map *map);
int			ft_valid_res_size(t_cub *cub);
int			ft_dark_color(int color, int dark);
int			ft_trim_color(char *long_str, unsigned int *c_color, char *c);
int			ft_init_cub(t_cub *cub, char *map_name);
int			ft_init_texture(t_cub *cub);
int			ft_init_mlx(t_cub *cub);
int			ft_ray_init(t_cub *cub);
int			ft_load_image(t_cub *cub);
int			ft_key_pressed(int keycode, t_cub *cub);
int			ft_key_released(int keycode, t_cub *cub);
int			player_moves(t_cub *cub, double x, double y);
int			ft_player_dir(t_cub *cub);
int			ft_player_rot(t_cub *cub, double rad);
int			ft_valid_moves(t_cub *cub);
int			ft_destroy_cub(t_cub *cub);
void		ft_set_rays_pos(t_cub *cub, int x);
void		ft_set_rays_dist(t_rays *rays);
void		ft_check_hit(t_cub *cub);
void		ft_set_project(t_rays *rays, t_map *map);
int			ft_read_map(char **line, int fd);
int			draw_backbg(t_cub *cub);
int			set_texture(t_cub *cub, t_game game);
int			put_texture(t_cub *cub, t_game game, int x);
int			ft_put_image(t_cub *cub);
int			ft_trim_map(t_map *map, char *long_str);
int			ft_player_position(t_map *map);
int			ft_trim_dir_tex(t_map *map);
int			ft_trim_resolution(char *long_str, int *w_size, int index);
char		*ft_trim_line(char *long_str, char *search_let);
int			ft_check_error(int argc, char **argv);
void		ft_freedouble(char **str);
int			ft_free_all(t_map *map, int flag);
int			ft_array_length(char **str);
int			is_digit(char *str);
int			get_r(int rgb);
int			get_g(int rgb);
int			get_b(int rgb);
int			ft_create_rgb(int r, int g, int b);

#endif
