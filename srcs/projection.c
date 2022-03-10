/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:05:14 by rantario          #+#    #+#             */
/*   Updated: 2022/03/10 11:07:37 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	make_points(t_environment *emu)
{
	int	i;
	int	j;

	i = 0;
	while (i < emu->row)
	{
		j = 0;
		while (j < emu->col)
		{
			emu->pts[i][j].x = ((j + 1) - emu->col / 2);
			emu->pts[i][j].y = ((i + 1) - emu->row / 2);
			emu->pts[i][j].z = emu->matrix[i][j];
			emu->init[i][j] = emu->pts[i][j];
			j++;
		}
		i++;
	}
}

t_point	trans_point_iso(t_point point, t_environment *emu)
{
	t_point	p_new;
	float	x;
	float	y;

	x = emu->scale * point.x * 0.866 + emu->scale * (point.y * 0.866);
	x = round_number(x);
	p_new.x = x + emu->x_offset;
	y = emu->scale_z * point.z + \
		emu->scale * (point.x * 0.5) - emu->scale * (point.y * 0.5);
	y = round_number(y);
	p_new.y = emu->y_offset - y;
	return (p_new);
}

t_point	trans_point_cab(t_point point, t_environment *emu)
{
	t_point	p_new;
	float	x;
	float	y;

	x = emu->scale * point.x * 0.707 + emu->scale * (point.y);
	x = round_number(x);
	p_new.x = x + emu->x_offset;
	y = emu->scale_z * point.z + emu->scale * (point.x * 0.707);
	y = round_number(y);
	p_new.y = emu->y_offset - y;
	return (p_new);
}

t_point	trans_point_plan(t_point point, t_environment *emu)
{
	t_point	p_new;
	float	x;
	float	y;

	x = emu->scale * point.x * 0.707 + emu->scale * (point.y * 0.707);
	x = round_number(x);
	p_new.x = x + emu->x_offset;
	y = emu->scale_z * point.z + \
		emu->scale * (point.x * 0.707) - emu->scale * (point.y * 0.707);
	y = round_number(y);
	p_new.y = emu->y_offset - y;
	return (p_new);
}

void	translate(t_environment *emu)
{
	int	i;
	int	j;

	i = 0;
	while (i < emu->row)
	{
		j = 0;
		while (j < emu->col)
		{
			if (emu->projection == 0)
				emu->trans[i][j] = trans_point_iso(emu->pts[i][j], emu);
			if (emu->projection == 1)
				emu->trans[i][j] = trans_point_cab(emu->pts[i][j], emu);
			if (emu->projection == 2)
				emu->trans[i][j] = trans_point_plan(emu->pts[i][j], emu);
			j++;
		}
		i++;
	}
}
