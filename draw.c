/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:15:01 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/08 13:26:36 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_position position, t_mlx *img, int color)
{
	int	offset;
	int	x;
	int	y;

	x = position.x;
	y = position.y;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}

void	ft_iterate(t_fractol *fractol, complex_number *c, complex_number *z,
		t_position position)
{
	int	i;
	int	color;

	i = 0;
	color = 0;
	while (i < fractol->iteration)
	{
		*z = set_z(*z, c, fractol->name);
		if (((z->x * z->x) + (z->y * z->y)) > 6)
		{
			color = scale(i, 0, 355, fractol->iteration);
			pixel_put(position, &fractol->mlx_value, color);
			return ;
		}
		++i;
	}
	pixel_put(position, &fractol->mlx_value, color);
}

void	set_complex(complex_number *z, complex_number *c, t_fractol *fractol,
		t_position position)
{
	z->x = scale(position.x, -2, +2, WIDTH) * fractol->zoom + fractol->shift_x;
	z->y = scale(position.y, +2, -2, WIDTH) * fractol->zoom + fractol->shift_y;
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	ft_do_math(int x, int y, t_fractol *fractol)
{
	complex_number	z;
	complex_number	c;
	t_position		position;

	position.x = x;
	position.y = y;
	set_complex(&z, &c, fractol, position);
	ft_iterate(fractol, &c, &z, position);
}

void	draw_img(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_do_math(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->mlx_value.img_ptr, 0, 0);
}
