#ifndef FT_FDF_H
# define FT_FDF_H


# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <errno.h>
# include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 2000
# endif
# define ERROR_MSG "Usage :./fdf <filename> [ case_size z_size ]\n"
# define INVALID_LEN "Found wrong line length. Exiting.\n"

typedef struct s_indexes
{
	int	x;
	int	y;
	int	zoom;
	int	zoom_height;
}	t_indexes;

typedef struct s_map_element
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_map_element;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		start_x;
	int		start_y;
}				t_data;

typedef struct s_bresenham
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

typedef struct s_position
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}	t_positions;

typedef struct s_graphics_arg
{
	int	points_number;
	int	elements_nb;
	int	lines_nb;
	int	max_z;
	int	pn;
}	t_graphics;

typedef struct s_numbers
{
	int	elements_nb;
	int	lines_nb;
}	t_numbers;

typedef struct s_fdf_utils
{
	int		line_iter;
	char	*line;
	char	*comma_pos;
	char	**elements;
	int		elements_nb;
	int		fd;

}	t_fdf_utils;
typedef struct s_structures
{
	t_map_element	*point;
	t_graphics		*graphical;
	t_data			*img;
	t_indexes		*size;
}	t_structures;

/* fdf functions */
void	free_elements(char **str);
void	fdf(int fd, t_numbers count, int argc, char *argv[]);

/* graphics part */
void	graphics_engine(t_map_element *point, t_graphics graphical, int argc,
			char *argv[]);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw_horizontal(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_draw_vertical(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_draw_horizontal_2d(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_draw_vertical_2d(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	iso(int *x, int *y, int z);
void	bresenham(t_data *img, t_positions pos, int color, t_indexes *size);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	iso_2d(int *x, int *y);
void	ft_put_string_to_win(t_data *img);
int		ft_buttons(int keycode, t_structures *ss);
void	ft_draw_vertical_rot(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_draw_horizontal_rot(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_draw_vertical_r(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_draw_horizontal_r(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_draw_vertical_l(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_draw_horizontal_l(t_graphics *graphical,
			t_map_element *point, t_data *img, t_indexes *size);
void	ft_put_string_to_win_2(t_data *img);
#endif
