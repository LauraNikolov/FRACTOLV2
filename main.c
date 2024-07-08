/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:18:46 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/08 14:37:16 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	manage_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	ft_error(int argc, char **argv, t_fractol *fractol)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 2)
		return (1);
	else if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
	{
		fractol->julia_x = ft_atod(argv[2]);
		fractol->julia_y = ft_atod(argv[3]);
		return (1);
	}
	else if ((argc == 2 && !ft_strncmp(argv[1], "burning bird", 12)))
		return (1);
	else if ((argc == 2 && !ft_strncmp(argv[1], "burning ship", 12)))
		return (1);
	else
	{
		ft_putstr_fd("please, enter valide argument", 2);
		return (0);
	}
}

t_complex_number	set_z(t_complex_number z, t_complex_number *c,
		char *fractal_name)
{
	if (!ft_strncmp(fractal_name, "burning bird", 12))
		return (z = addition_complex_number(ft_burning_bird(z), *c));
	else if (!ft_strncmp(fractal_name, "burning ship", 12))
		return (z = addition_complex_number(ft_burning_ship(z), *c));
	else
		return (z = addition_complex_number(multiply_complex_number(z), *c));
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	ft_memset(&fractol, 0, sizeof(fractol));
	if (ft_error(argc, argv, &fractol) == 1)
	{
		fractol.name = argv[1];
		fractol.escape_value = 4;
		fractol.iteration = 42;
		fractol.zoom = 1.0;
		ft_fractal(&fractol);
	}
}
