#include "ft_fdf.h"

void draw_line(t_env *emu)
{
	emu->line.dx = fabs(emu->p2.x - emu->p1.x);
	emu->line.dy = fabs(emu->p2.y - emu->p1.y);
	emu->line.sign_x = emu->p1.x < emu->p2.x ? 1 : -1;
	emu->line.sign_y = emu->p1.y < emu->p2.y ? 1 : -1;
	emu->line.error1 = emu->line.dx - emu->line.dy;
	while (emu->p1.x != emu->p2.x || emu->p1.y != emu->p2.y)
	{
		put_pixel_img(emu, emu->p1.x, emu->p1.y, emu->line.color);
		emu->line.error2 = emu->line.error1 * 2;
		if (emu->line.error2 > -(emu->line.dy))
		{
			emu->line.error1 -= emu->line.dy;
			emu->p1.x += emu->line.sign_x;
		}
		if (emu->line.error2 < emu->line.dx)
		{
			emu->line.error1 += emu->line.dx;
			emu->p1.y += emu->line.sign_y;
		}
	}
}

void draw_picture_1(t_env *emu)
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
			emu->p1 = emu->trans[i][j++];
			emu->p2 = emu->trans[i][j];
			draw_line(emu);
		}
	}
}

void draw_picture_2(t_env *emu)
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
			emu->p1 = emu->trans[i++][j];
			emu->p2 = emu->trans[i][j];
			draw_line(emu);
		}
	}
}

void put_pixel_img(t_env *emu, int x, int y, int color)
{
	char *px;
	int p;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		px = mlx_get_data_addr(emu->image, &p, &p, &p);
		p = WIDTH * y * 4 + x * 4;
		px[p + 0] = get_red(color);
		px[p + 1] = get_green(color);
		px[p + 2] = get_blue(color);
	}
}

void img_clear(t_env *emu)
{
	char *px;
	int p;

	px = mlx_get_data_addr(emu->image, &p, &p, &p);
	ft_bzero(px, 4 * WIDTH * HEIGHT);
}
