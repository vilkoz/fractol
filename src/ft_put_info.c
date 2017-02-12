/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:26:17 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/12 16:31:51 by vrybalko         ###   ########.fr       */
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
		ft_putstry(e, "fractal: mundelbrot");
	if (e->f_type == 2)
		ft_putstry(e, "fractal: burning ship");
	if (e->f_type == 3)
		ft_putstry(e, "fractal: sinusoidal");
}

void		ft_put_info(t_e *e)
{
	ft_putstry(e, ft_strjoin("Zoom: ", ft_itoa((int)(e->zo * 1000))));
	ft_putstry(e, ft_strjoin("x shift: ", ft_itoa(e->x_sh * 1000)));
	ft_putstry(e, ft_strjoin("y shift: ", ft_itoa(e->y_sh * 1000)));
	ft_put_fractal_type(e);
	ft_putstry(e, ft_strjoin("iterations: ", ft_itoa(e->max)));
	ft_putstry(e, ft_strjoin("e->f_type: ", ft_itoa(e->f_type)));
	ft_putstry(e, ft_strjoin("e->k.tr_d: ", ft_itoa(e->k.tr_d)));
	e->txt_shift = 0;
}
