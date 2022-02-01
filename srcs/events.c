#include "ft_fdf.h"

int key_handling(int key_code, t_env *emu)
{
	ft_putendl(ft_itoa(key_code));
	if (key_code == 65307)
	{
		ft_putendl("Exit");
		exit(0);
	}
	if (key_code == 114)
		emu->color = 1;
	if (key_code == 103)
		emu->color = 2;
	if (key_code == 98)
		emu->color = 3;
	if (key_code == 105)
		emu->color = 0;
	event_1(key_code, emu);
	event_2(key_code, emu);
	if (key_code == 48)
		set_default(emu);
	translate(emu);
	return (0);
}

void event_1(int key_code, t_env *emu)
{
	if (key_code == 61)
		emu->scale += 5;
	if (key_code == 45)
	{
		if (emu->scale != 1)
			emu->scale -= 5;
	}
	if (key_code == 97)
		emu->x_offset -= 5;
	if (key_code == 100)
		emu->x_offset += 5;
	if (key_code == 119)
		emu->y_offset -= 5;
	if (key_code == 115)
		emu->y_offset += 5;
	if (key_code == 91)
		emu->scale_z++;
	if (key_code == 93)
		emu->scale_z--;
}

void event_2(int key_code, t_env *emu)
{
	if (key_code == 49)
		emu->projection = 0;
	if (key_code == 50)
		emu->projection = 1;
	if (key_code == 51)
		emu->projection = 2;
	if (key_code == 101)
		x_rotation(emu, 0.019);
	if (key_code == 113)
		x_rotation(emu, -0.019);
	if (key_code == 65361)
		z_rotation(emu, 0.019);
	if (key_code == 65363)
		z_rotation(emu, -0.019);
	if (key_code == 65362)
		y_rotation(emu, -0.019);
	if (key_code == 65364)
		y_rotation(emu, 0.019);
}

void set_default(t_env *emu)
{
	int i;
	int j;

	i = 0;
	emu->scale = 30;
	emu->scale_z = 2;
	emu->x_offset = WIDTH / 2;
	emu->y_offset = HEIGHT / 2;
	while (i < emu->row)
	{
		j = 0;
		while (j < emu->col)
		{
			emu->pts[i][j] = emu->init[i][j];
			j++;
		}
		i++;
	}
}
