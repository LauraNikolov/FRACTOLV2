/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:15:01 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/02 18:32:48 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	opti_pixel_put(int x, int y, t_mlx *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}


complex_number	set_z(complex_number z, complex_number *c, char *fractal_name)
{
	if (!ft_strncmp(fractal_name, "= (0burning bird", 12))
		return (z = addition_complex_number(ft_burning_bird(z), *c));
	else if (!ft_strncmp(fractal_name, "burning ship", 12))
		return (z = addition_complex_number(ft_burning_ship(z), *c));
	else
		return (z = addition_complex_number(multiply_complex_number(z), *c));
}

void ft_iterate(t_fractol *fractol, complex_number *c, complex_number *z, int x, int y)
{
    int i;
    int color;

    i = 0;
    color = 0;
    while(i < fractol->iteration)
    {
        *z = set_z(*z, c, fractol->name);
        if(((z->x * z->x) + (z->y * z->y)) > 6)
        {
            color = scale(i, 0, 355, fractol->iteration);
			opti_pixel_put(x, y, &fractol->mlx_value, color);
			return ;
        }
        ++i;
    }
    
    opti_pixel_put(x, y, &fractol->mlx_value, color);
}


void set_complex(complex_number *z, complex_number *c, t_fractol *fractol, int x, int y)
{
    z->x = scale(x, -2, +2, WIDTH) * fractol->zoom + fractol->shift_x;
    z->y = scale(y, +2, -2, WIDTH) * fractol->zoom + fractol->shift_y;
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


void ft_do_math(int x, int y, t_fractol *fractol)
{
    complex_number z;
    complex_number c;

    set_complex(&z, &c, fractol, x, y);
    ft_iterate(fractol, &c, &z, x, y);
}


void draw_img(t_fractol *fractol)
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