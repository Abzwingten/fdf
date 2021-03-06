/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:31:43 by rantario          #+#    #+#             */
/*   Updated: 2022/03/10 13:35:51 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	round_number(float number)
{
	int		dec;
	float	floating;
	int		flag;

	flag = 1;
	if (number < 0)
	{
		number *= -1;
		flag = -1;
	}
	dec = number;
	floating = number - (int)number;
	if (floating < 0.5)
		return ((int)(dec * flag));
	return ((int)((dec + 1) * flag));
}

void	calculate_x_rot(float *y, float *z, float angle)
{
	float	y_init;
	float	z_init;

	y_init = *y;
	z_init = *z;
	(*y) = y_init * cosf(angle) + (z_init) * sinf(angle);
	(*z) = (-y_init) * sinf(angle) + z_init * cosf(angle);
}

void	calculate_y_rot(float *x, float *z, float angle)
{
	float	x_init;
	float	z_init;

	x_init = *x;
	z_init = *z;
	(*x) = x_init * cosf(angle) + (z_init) * sinf(angle);
	(*z) = (-x_init) * sinf(angle) + z_init * cosf(angle);
}

void	calculate_z_rot(float *x, float *y, float angle)
{
	float	y_init;
	float	x_init;

	y_init = (*y);
	x_init = (*x);
	(*x) = x_init * cosf(angle) - y_init * sinf(angle);
	(*y) = x_init * sinf(angle) + y_init * cosf(angle);
}

int	**make_matrix(char **map, t_environment *emu)
{
	int		j;
	int		k;
	int		len;
	int		**arr;
	char	**split_str;

	arr = (int **)malloc(sizeof(int *) * emu->row);
	j = 0;
	len = 0;
	while (j < emu->row)
	{
		k = -1;
		split_str = ft_split(map[j], ' ');
		while (split_str[len])
			len++;
		arr[j] = (int *)malloc(sizeof(int) * len);
		while (split_str[++k])
			arr[j][k] = ft_atoi(split_str[k]);
		j++;
	}
	emu->col = len;
	return (arr);
}
