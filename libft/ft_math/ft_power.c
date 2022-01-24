/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:12:41 by rantario          #+#    #+#             */
/*   Updated: 2021/12/30 18:13:02 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int num, unsigned int power)
{
	int	res;

	res = 1;
	while (num)
	{
		if (num & 1)
			res *= power;
		power *= power;
		num >>= 1;
	}
	return (res);
}
