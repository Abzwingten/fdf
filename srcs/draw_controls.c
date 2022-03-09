/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:35:14 by rantario          #+#    #+#             */
/*   Updated: 2022/03/09 20:35:34 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_draw_controls(t_environment *emu)
{
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 70, 0x00FFFF00, \
					"W/A/S/D to move image");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 60, 0x00FFFF00, \
					"-/+ to scale image");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 50, 0x00FFFF00, \
					"R/G/B - to change colors");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 40, 0x00FFFF00, \
					"Q/E - for x axis rotation");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 30, 0x00FFFF00, \
					"arrow up/arrow down - for z axis rotation");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 20, 0x00FFFF00, \
					"arrow left/arrow right - for y axis rotation");
	mlx_string_put(emu->mlx, emu->window, 10, HEIGHT - 10, 0x00FFFF00, \
					"ESC - for exit");
}
