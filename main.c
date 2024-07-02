/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:18:46 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/02 18:28:05 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"


int ft_error(int argc, char **argv, t_fractol *fractol)
{
    if(!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 2)
        return(1);
    else if(!ft_strncmp(argv[1], "julia", 5) && argc == 4)
    {
        fractol->julia_x = ft_atod(argv[2]);
        fractol->julia_y = ft_atod(argv[3]);
        return(1);
    }
    else if((argc == 2 && !ft_strncmp(argv[1], "burning bird", 12)))
        return(1);
    else if((argc == 2 && !ft_strncmp(argv[1], "burning ship", 12)))
        return(1);
    else{
        ft_putstr_fd("please, enter valide argument", 2);
        return(0);
    }
}


void ft_fractal(t_fractol *fractol)
{
    init_mlx(fractol);
    draw_img(fractol);
    mlx_loop(fractol->mlx_connection);
}

int main(int argc, char **argv)
{
    t_fractol fractol;
    
    ft_memset(&fractol, 0, sizeof(fractol));
    if(ft_error(argc, argv, &fractol) == 1)
    {
        fractol.name = argv[1];
        fractol.escape_value = 4;
	    fractol.iteration = 42;
	    fractol.zoom = 1.0;
        ft_fractal(&fractol);
    }
}
