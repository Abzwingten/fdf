/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:58:51 by rantario          #+#    #+#             */
/*   Updated: 2022/03/09 20:22:05 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	key_handling(int key_code, t_environment *emu)
{
	ft_putendl(ft_itoa(key_code));
	if (key_code == KEY_ESC)
	{
		ft_putendl("Exit");
		exit(0);
	}
	if (key_code == KEY_R)
		emu->color = 1;
	if (key_code == KEY_G)
		emu->color = 2;
	if (key_code == KEY_B)
		emu->color = 3;
	if (key_code == KEY_I)
		emu->color = 0;
	key_prs_off(key_code, emu);
	key_prs_rot(key_code, emu);
	if (key_code == KEY_0)
		set_default(emu);
	translate(emu);
	return (0);
}

void	key_prs_off(int key_code, t_environment *emu)
{
	if (key_code == KEY_PLUS)
		emu->scale += 1;
	if (key_code == KEY_MINUS)
	{
		if (emu->scale != 1)
			emu->scale -= 1;
	}
	if (key_code == KEY_A)
		emu->x_offset -= 5;
	if (key_code == KEY_D)
		emu->x_offset += 5;
	if (key_code == KEY_W)
		emu->y_offset -= 5;
	if (key_code == KEY_S)
		emu->y_offset += 5;
	if (key_code == KEY_BR_L)
		emu->scale_z++;
	if (key_code == KEY_BR_R)
		emu->scale_z--;
}

void	key_prs_rot(int key_code, t_environment *emu)
{
	if (key_code == KEY_1)
		emu->projection = 0;
	if (key_code == KEY_2)
		emu->projection = 1;
	if (key_code == KEY_3)
		emu->projection = 2;
	if (key_code == KEY_E)
		x_rotation(emu, 0.019);
	if (key_code == KEY_Q)
		x_rotation(emu, -0.019);
	if (key_code == KEY_LEFT)
		z_rotation(emu, 0.019);
	if (key_code == KEY_RIGHT)
		z_rotation(emu, -0.019);
	if (key_code == KEY_UP)
		y_rotation(emu, -0.019);
	if (key_code == KEY_DOWN)
		y_rotation(emu, 0.019);
}

void	set_default(t_environment *emu)
{
	int	i;
	int	j;

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
