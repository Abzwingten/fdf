#include "ft_fdf.h"

void make_points(t_environment *w)
{
	int i;
	int j;

	i = 0;
	while (i < w->row)
	{
		j = 0;
		while (j < w->col)
		{
			w->pts[i][j].x = ((j + 1) - w->col / 2);
			w->pts[i][j].y = ((i + 1) - w->row / 2);
			w->pts[i][j].z = w->matrix[i][j];
			w->init[i][j] = w->pts[i][j];
			j++;
		}
		i++;
	}
}

t_point trans_point_iso(t_point point, t_environment *w)
{
	t_point p_new;
	float x;
	float y;

	x = w->scale * point.x * 0.866 + w->scale * (point.y * 0.866);
	x = round_number(x);
	p_new.x = x + w->x_offset;
	y = w->scale_z * point.z + w->scale * (point.x * 0.5) - w->scale * (point.y * 0.5);
	y = round_number(y);
	p_new.y = w->y_offset - y;
	return (p_new);
}

t_point trans_point_cab(t_point point, t_environment *w)
{
	t_point p_new;
	float x;
	float y;

	x = w->scale * point.x * 0.707 + w->scale * (point.y);
	x = round_number(x);
	p_new.x = x + w->x_offset;
	y = w->scale_z * point.z + w->scale * (point.x * 0.707);
	y = round_number(y);
	p_new.y = w->y_offset - y;
	return (p_new);
}

t_point trans_point_plan(t_point point, t_environment *w)
{
	t_point p_new;
	float x;
	float y;

	x = w->scale * point.x * 0.707 + w->scale * (point.y * 0.707);
	x = round_number(x);
	p_new.x = x + w->x_offset;
	y = w->scale_z * point.z + w->scale * (point.x * 0.707) - w->scale * (point.y * 0.707);
	y = round_number(y);
	p_new.y = w->y_offset - y;
	return (p_new);
}

void translate(t_environment *w)
{
	int i;
	int j;

	i = 0;
	while (i < w->row)
	{
		j = 0;
		while (j < w->col)
		{
			if (w->projection == 0)
				w->trans[i][j] = trans_point_iso(w->pts[i][j], w);
			if (w->projection == 1)
				w->trans[i][j] = trans_point_cab(w->pts[i][j], w);
			if (w->projection == 2)
				w->trans[i][j] = trans_point_plan(w->pts[i][j], w);
			j++;
		}
		i++;
	}
}
