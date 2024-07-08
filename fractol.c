/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:51:33 by lnicolof          #+#    #+#             */
/*   Updated: 2024/07/08 14:33:48 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*À chaque itération nn :

	Prendre la partie réelle ℜ(zn)ℜ(zn​) du nombre complexe znzn​.
	Prendre la partie imaginaire ℑ(zn)ℑ(zn​) du nombre complexe znzn​.
	Calculer la valeur absolue de chaque partie.
	Ajouter la partie réelle et la partie imaginaire multipliée par i.
	Calculer le carré de cette somme.
	Ajouter une constante complexe c.*/

t_complex_number	ft_burning_bird(t_complex_number z)
{
	t_complex_number	result;

	result.x = z.x * z.x - z.y * z.y;
	result.y = (-2) * (z.x) * negative_complex_number(z.y);
	return (result);
}

/*
À chaque itération :

	Prendre la partie réelle ℜ(zn)ℜ(zn​) du nombre complexe znzn​.
	Prendre la partie imaginaire ℑ(zn)ℑ(zn​) du nombre complexe znzn​.
	Calculer le carré de chaque partie.
	Soustraire le carré de la partie imaginaire à celui de la partie réelle.
	Ajouter une constante complexe c.
*/
t_complex_number	ft_burning_ship(t_complex_number z)
{
	t_complex_number	result;

	result.x = z.x * z.x - z.y * z.y;
	result.y = -2 * negative_complex_number(z.x * z.y);
	return (result);
}

void	ft_fractal(t_fractol *fractol)
{	
	init_mlx(fractol);
	draw_img(fractol);
	mlx_loop(fractol->mlx_connection);
}
