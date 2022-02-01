#include "ft_fdf.h"

void x_rotation(t_env *emu, float angle)
{
	int i;
	int j;

	i = 0;
	while (i < emu->row)
	{
		j = 0;
		while (j < emu->col)
		{
			calc_x_rot(&(emu->pts[i][j].y), &(emu->pts[i][j].z), angle);
			j++;
		}
		i++;
	}
}

void y_rotation(t_env *emu, float angle)
{
	int i;
	int j;

	i = 0;
	while (i < emu->row)
	{
		j = 0;
		while (j < emu->col)
		{
			calc_y_rot(&(emu->pts[i][j].x), &(emu->pts[i][j].z), angle);
			j++;
		}
		i++;
	}
}

void z_rotation(t_env *emu, float angle)
{
	int i;
	int j;

	i = 0;
	while (i < emu->row)
	{
		j = 0;
		while (j < emu->col)
		{
			calc_z_rot(&(emu->pts[i][j].x), &(emu->pts[i][j].y), angle);
			j++;
		}
		i++;
	}
}
