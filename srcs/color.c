/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:30:18 by rantario          #+#    #+#             */
/*   Updated: 2022/03/09 20:31:03 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	set_color_1(t_environment *emu, int i, int j)
{
	if ((emu->init[i][j].z < emu->init[i][j + 1].z) \
		|| (emu->init[i][j].z > emu->init[i][j + 1].z))
	{
		if (emu->color == 0)
			emu->line.color = 0x0646464;
		if (emu->color == 1)
			emu->line.color = 0x00000FF;
		if (emu->color == 2)
			emu->line.color = 0x000FF00;
		if (emu->color == 3)
			emu->line.color = 0x0FF0000;
	}
}

void	set_color_2(t_environment *emu, int i, int j)
{
	if ((emu->init[i][j].z < emu->init[i + 1][j].z) \
		|| (emu->init[i][j].z > emu->init[i + 1][j].z))
	{
		if (emu->color == 0)
			emu->line.color = 0x0646464;
		if (emu->color == 1)
			emu->line.color = 0x00000FF;
		if (emu->color == 2)
			emu->line.color = 0x000FF00;
		if (emu->color == 3)
			emu->line.color = 0x0FF0000;
	}
}

int	get_red(int color)
{
	return ((int)(((color >> 16) & 0xFF)));
}

int	get_green(int color)
{
	return ((int)(((color >> 8) & 0xFF)));
}

int	get_blue(int color)
{
	return ((int)((color) & 0xFF));
}
