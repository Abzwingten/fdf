#include "ft_fdf.h"

void draw_line(t_environment *emu)
{
	emu->line.dx = fabs(emu->point2.x - emu->point_1.x);
	emu->line.dy = fabs(emu->point2.y - emu->point_1.y);
	emu->line.sign_x = emu->point_1.x < emu->point2.x ? 1 : -1;
	emu->line.sign_y = emu->point_1.y < emu->point2.y ? 1 : -1;
	emu->line.error1 = emu->line.dx - emu->line.dy;
	while (emu->point_1.x != emu->point2.x || emu->point_1.y != emu->point2.y)
	{
		put_pixel_img(emu, emu->point_1.x, emu->point_1.y, emu->line.color);
		emu->line.error2 = emu->line.error1 * 2;
		if (emu->line.error2 > -(emu->line.dy))
		{
			emu->line.error1 -= emu->line.dy;
			emu->point_1.x += emu->line.sign_x;
		}
		if (emu->line.error2 < emu->line.dx)
		{
			emu->line.error1 += emu->line.dx;
			emu->point_1.y += emu->line.sign_y;
		}
	}
}

void draw_picture_1(t_environment *emu)
{
	int i;
	int j;

	i = -1;
	while (++i < emu->row)
	{
		j = 0;
		while (j < emu->col - 1)
		{
			emu->line.color = 0x00FFFFFF;
			set_color_1(emu, i, j);
			emu->point_1 = emu->trans[i][j++];
			emu->point2 = emu->trans[i][j];
			draw_line(emu);
		}
	}
}

void draw_picture_2(t_environment *emu)
{
	int i;
	int j;

	j = -1;
	while (++j < emu->col)
	{
		i = 0;
		while (i < emu->row - 1)
		{
			emu->line.color = 0x00FFFFFF;
			set_color_2(emu, i, j);
			emu->point_1 = emu->trans[i++][j];
			emu->point2 = emu->trans[i][j];
			draw_line(emu);
		}
	}
}

void put_pixel_img(t_environment *emu, int x, int y, int color)
{
	char *px;
	int point;

	if ((x > 0 && x < FT_WIDTH) && (y > 0 && y < HEIGHT))
	{
		px = mlx_get_data_addr(emu->image, &point, &point, &point);
		point = FT_WIDTH * y * 4 + x * 4;
		px[point + 0] = get_red(color);
		px[point + 1] = get_green(color);
		px[point + 2] = get_blue(color);
	}
}

void img_clear(t_environment *emu)
{
	char *px;
	int point;

	px = mlx_get_data_addr(emu->image, &point, &point, &point);
	ft_bzero(px, 4 * FT_WIDTH * HEIGHT);
}
