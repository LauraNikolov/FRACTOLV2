/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:15:44 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/08 13:38:25 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 799
# define HEIGHT 799

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

struct s_complex_number
{
	double		x;
	double		y;
}				complex_number;

typedef struct s_mlx
{
	void		*img_ptr;
	char		*pix_ptr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_mlx;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_mlx		mlx_value;
	double		escape_value;
	int			iteration;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}				t_fractol;

void			init_mlx(t_fractol *fractol);
int				ft_error(int argc, char **argv, t_fractol *fractol);
complex_number	ft_burning_ship(complex_number z);
double			negative_complex_number(double nb);
complex_number	multiply_complex_number(complex_number z);
complex_number	addition_complex_number(complex_number z1, complex_number z2);
double			scale(double unscaled_num, double new_min, double new_max,
					double old_max);
void			draw_img(t_fractol *fractol);
int				ft_exit(t_fractol *fractol);
complex_number	ft_burning_bird(complex_number z);
complex_number	ft_burning_ship(complex_number z);
int				ft_exit(t_fractol *fractol);
int				manage_mouse(int button, int x, int y, t_fractol *fractol);
int				manage_keyboard(int keysym, t_fractol *fractol);
double			ft_atod(char *s);
void			manage_error(char *str);
void			ft_fractal(t_fractol *fractol);
complex_number	set_z(complex_number z, complex_number *c, char *fractal_name);

#endif
