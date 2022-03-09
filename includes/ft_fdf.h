/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:31:50 by rantario          #+#    #+#             */
/*   Updated: 2022/03/09 20:23:35 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define WIDTH 1024
# define HEIGHT 600

# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <libft.h>

# if defined(__APPLE__)
#  define KEY_W 13
#  define KEY_D 2
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_PLUS 24
#  define KEY_MINUS 78
#  define KEY_ESC 53
#  define KEY_1 18
#  define KEY_2 12
#  define KEY_3 20
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_R 15
#  define KEY_G 5
#  define KEY_B 11
#  define KEY_I 34
#  define KEY_0 29
#  define KEY_E 14
#  define KEY_Q 12
#  define KEY_BR_L 33
#  define KEY_BR_R 30

# elif __linux__
#  define KEY_W 119
#  define KEY_D 100
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_PLUS 61
#  define KEY_MINUS 45
#  define KEY_ESC 65307
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_R 114
#  define KEY_G 103
#  define KEY_B 98
#  define KEY_I 105
#  define KEY_0 48
#  define KEY_E 101
#  define KEY_Q 113
#  define KEY_BR_L 91
#  define KEY_BR_R 93
# endif

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_line
{
	int	error1;
	int	error2;
	int	sign_x;
	int	sign_y;
	int	dx;
	int	dy;
	int	color;
}	t_line;

typedef struct s_environment
{
	void	*mlx;
	void	*window;
	void	*image;
	int		**matrix;
	int		row;
	int		col;
	int		scale;
	int		scale_z;
	int		x_offset;
	int		y_offset;
	int		projection;
	int		color;
	t_point	point_1;
	t_point	point2;
	t_point	**init;
	t_point	**pts;
	t_point	**trans;
	t_line	line;
}	t_environment;

void	ft_error(int argc, int fd);
void	set_basic(t_environment *emu);
void	key_prs_off(int key_code, t_environment *emu);
void	key_prs_rot(int key_code, t_environment *emu);
void	draw_picture_1(t_environment *emu);
void	draw_picture_2(t_environment *emu);
void	create_window(t_environment *emu);
void	draw_line(t_environment *emu);
void	set_default(t_environment *emu);
void	set_color_1(t_environment *emu, int i, int j);
void	set_color_2(t_environment *emu, int i, int j);
void	put_pixel_img(t_environment *emu, int x, int y, int color);
void	img_clear(t_environment *emu);
void	translate(t_environment *emu);
void	choose_color_1(t_environment *emu, int i, int j);
void	choose_color_2(t_environment *emu, int i, int j);
void	x_rotation(t_environment *emu, float angle);
void	y_rotation(t_environment *emu, float angle);
void	z_rotation(t_environment *emu, float angle);
void	calc_x_rot(float *y, float *z, float angle);
void	calc_y_rot(float *x, float *z, float angle);
void	calc_z_rot(float *x, float *y, float angle);
void	make_points(t_environment *emu);
int		main_activity(t_environment *emu);
int		key_handling(int key_code, t_environment *emu);
int		**make_matrix(char **map, t_environment *emu);
int		round_number(float number);
int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
void	ft_draw_controls(t_environment *emu);
t_point	trans_point_iso(t_point point, t_environment *emu);
t_point	trans_point_cab(t_point point, t_environment *emu);
t_point	trans_point_plan(t_point point, t_environment *emu);

#endif
