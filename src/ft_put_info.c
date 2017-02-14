/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:26:17 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/14 19:29:20 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		ft_putstry(t_e *e, char *str)
{
	e->txt_shift += 15;
	mlx_string_put(e->mlx, e->win, 15, e->txt_shift, 0xffffff, str);
}

void		ft_put_fractal_type(t_e *e)
{
	if (e->f_type == 0)
		ft_putstry(e, "fractal: julia");
	if (e->f_type == 1)
		ft_putstry(e, "fractal: mandelbrot");
	if (e->f_type == 2)
		ft_putstry(e, "fractal: burning ship");
	if (e->f_type == 3)
		ft_putstry(e, "fractal: sinusoidal");
	if (e->f_type == 4)
		ft_putstry(e, "fractal: koch snowflake");
	if (e->f_type == 5)
		ft_putstry(e, "fractal: sierpinski triangle");
}

void		ft_put_info(t_e *e)
{
	ft_putstry(e, ft_strjoin("Zoom: ", ft_itoa((int)(e->zo * 100))));
	ft_put_fractal_type(e);
	if (e->f_type == 0 && e->k.m_co == 1)
		ft_putstry(e, "mouse control: on");
	if (e->f_type == 0 && e->k.m_co == 0)
		ft_putstry(e, "mouse control: off");
	ft_putstry(e, "Controls:");
	ft_putstry(e, "mwhell - zoom at mouse point");
	ft_putstry(e, "+,-    - zoom at center");
	ft_putstry(e, "arrows - movement");
	ft_putstry(e, "3      - enable 3D (if avalible)");
	ft_putstry(e, "M      - on / off mouse control (julia)");
	e->txt_shift = 0;
}
