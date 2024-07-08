/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:41:39 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/08 13:33:36 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->mlx_value.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(0);
}

int	manage_keyboard(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		ft_exit(fractol);
	if (keysym == XK_Left)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y += (0.5 * fractol->zoom);
	draw_img(fractol);
	return (0);
}

int	manage_mouse(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractol->zoom *= 0.95;
	else if (button == Button4)
		fractol->zoom *= 1.25;
	draw_img(fractol);
	return (0);
}

static void	mlx_events(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iteration = 45;
	fractol->zoom = 1.0;
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, manage_keyboard,
		fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask, manage_mouse,
		fractol);
	mlx_hook(fractol->mlx_window, 17, 0, ft_exit, fractol);
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		manage_error("mlx_init failed\n");
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT,
			"fractol");
	if (!fractol->mlx_window)
	{
		free(fractol->mlx_connection);
		manage_error("mlx_new_window failed\n");
	}
	fractol->mlx_value.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH,
			HEIGHT);
	if (!fractol->mlx_value.img_ptr)
	{
		free(fractol->mlx_connection);
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		manage_error("mlx_new_image failed\n");
	}
	fractol->mlx_value.pix_ptr = mlx_get_data_addr(fractol->mlx_value.img_ptr,
			&fractol->mlx_value.bpp, &fractol->mlx_value.line_len,
			&fractol->mlx_value.endian);
	mlx_events(fractol);
}
