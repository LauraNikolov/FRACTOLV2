/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:48:54 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/02 18:28:57 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double unscaled_num, double new_min, double new_max,
		double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);
}

complex_number	addition_complex_number(complex_number z1, complex_number z2)
{
	complex_number	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

complex_number	multiply_complex_number(complex_number z)
{
	complex_number	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}


double	negative_complex_number(double nb)
{
	if (nb < 0.0)
		nb *= -1;
	return (nb);
}

double	ft_atod(char *s)
{
	int		i;
	int		sign;
	double	nbr;
	double	fraction;

	sign = 1;
	nbr = 0.0;
	fraction = 0.1;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '.')
		nbr = nbr * 10 + (s[i++] - '0');
	i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr + (fraction * (s[i++] - '0'));
		fraction /= 10;
	}
	return (nbr * sign);
}
