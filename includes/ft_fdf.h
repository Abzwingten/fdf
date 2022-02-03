#ifndef FT_FDF_H
# define FT_FDF_H

#define WIDTH 1024
#define HEIGHT 600

# include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_point
{
	float x;
	float y;
	float z;
} t_point;

typedef struct s_line
{
	int error1;
	int error2;
	int sign_x;
	int sign_y;
	int dx;
	int dy;
	int color;
} t_line;

typedef struct s_environment
{
	void *mlx;
	void *window;
	void *image;
	int **matrix;
	int row;
	int col;
	int scale;
	int scale_z;
	int x_offset;
	int y_offset;
	int projection;
	int color;
	t_point point_1;
	t_point point2;
	t_point **init;
	t_point **pts;
	t_point **trans;
	t_line line;
} t_environment;

void ft_error(int argc, int fd);
void set_basic(t_environment *emu);
void key_prs_off(int key_code, t_environment *emu);
void key_prs_rot(int key_code, t_environment *emu);
void draw_picture_1(t_environment *emu);
void draw_picture_2(t_environment *emu);
void create_window(t_environment *emu);
void draw_line(t_environment *emu);
void set_default(t_environment *emu);
void set_color_1(t_environment *emu, int i, int j);
void set_color_2(t_environment *emu, int i, int j);
void put_pixel_img(t_environment *emu, int x, int y, int color);
void img_clear(t_environment *emu);
void translate(t_environment *emu);
void choose_color_1(t_environment *emu, int i, int j);
void choose_color_2(t_environment *emu, int i, int j);
void x_rotation(t_environment *emu, float angle);
void y_rotation(t_environment *emu, float angle);
void z_rotation(t_environment *emu, float angle);
void calc_x_rot(float *y, float *z, float angle);
void calc_y_rot(float *x, float *z, float angle);
void calc_z_rot(float *x, float *y, float angle);
void make_points(t_environment *emu);
int main_activity(t_environment *emu);
int key_handling(int key_code, t_environment *emu);
int **make_matrix(char **map, t_environment *emu);
int round_number(float number);
int get_red(int color);
int get_green(int color);
int get_blue(int color);
void ft_draw_controls(t_environment *emu);
t_point trans_point_iso(t_point point, t_environment *emu);
t_point trans_point_cab(t_point point, t_environment *emu);
t_point trans_point_plan(t_point point, t_environment *emu);

#endif
